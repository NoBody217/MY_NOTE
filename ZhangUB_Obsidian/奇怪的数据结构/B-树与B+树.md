- 用于大数据量（如数据库、文件系统）在磁盘上的索引结构，减少磁盘I/O次数
- 重点看富有的概念
## 一、B-树（B-Tree）

### 1.1 概念

- B-树是一种多路搜索树，广泛应用于数据库和文件系统中。
- 它保持数据有序，并支持高效的插入、删除、查找操作。
- 每个节点可以有多个孩子节点（不像二叉树只有两个）。 
- 一个 m 阶的 B-树具有以下性质：
    1. 每个节点最多有 m 个孩子；
    2. 除根节点外，所有节点至少有 ⌈m/2⌉ 个孩子；
    3. 所有叶子节点都在同一层；
    4. 每个非叶节点包含 ⌈m/2⌉−1 到 m−1 个键。
### 1.2 B-树操作实现

以下以阶数为 3 的 B-树为例：
#### 节点结构：
```c
#define MAX 3
#define MIN 2

typedef struct BTreeNode {
    int val[MAX + 1]; // 最大3个键
    struct BTreeNode *child[MAX + 2]; // 最多4个孩子
    int n; // 当前键个数
    int leaf; // 是否为叶子
} BTreeNode;
```
#### 插入操作：
```c
void insert(int key, BTreeNode **root);
void insertNonFull(BTreeNode *node, int key);
void splitChild(BTreeNode *parent, int i, BTreeNode *child);
```

- 时间复杂度：**O(log n)**，因为高度约为 logₘn，插入最多涉及一次分裂。
#### 查找操作：

```c
BTreeNode* search(BTreeNode *node, int key) {
    int i = 0;
    while (i < node->n && key > node->val[i])
        i++;
    if (i < node->n && key == node->val[i])
        return node;
    if (node->leaf)
        return NULL;
    return search(node->child[i], key);
}
```

- 时间复杂度：**O(log n)**，每层查找 O(log m)，高度 O(logₘ n)。
#### 删除操作：
- **富有**：删除一个key后，结点剩余的key的数量依然大于等于ceil(m/2)-1
- B-树删除总能变为删除一个叶子节点的一个data：类比二叉搜索树
- 对于一个叶子节点如果富有直接删除
- 反之则考虑向兄弟借一个结点：
	- 先拿父亲一个，父亲拿兄弟一个
	- 如果所有兄弟都不富有，那就让父亲找父亲的兄弟借
	- 如果直到根都不富有，就降低树高度
- 以及该合并的时候合并
- 时间复杂度：**O(log n)**

---

## 二、B+树（B+Tree）

### 2.1 概念
- B+树是 B-树的变体，广泛用于数据库系统的索引。
- 所有键都出现在叶子节点，内部节点只作为索引。
- 叶子节点通过指针链表连接，便于范围查询。
### 2.2 特点对比（与 B-树）：

| 特性       | B-树       | B+树         |
| -------- | --------- | ----------- |
| 数据存储     | 内部节点和叶子节点 | 仅叶子节点       |
| 范围查询效率   | 较低        | 高（通过链表快速遍历） |
| 非叶节点是否存值 | 是         | 否           |
| 叶节点是否有序链 | 否         | 是（链式结构）     |

### 2.3 B+树操作实现
以下以阶数为 3 的 B+树为例：
#### 节点结构：

```c
typedef struct BPTreeNode {
    int val[MAX + 1];
    struct BPTreeNode *child[MAX + 2];
    struct BPTreeNode *next; // 指向下一个叶子
    int n;
    int leaf;
} BPTreeNode;
```
#### 插入操作：
```c
void insertBP(int key, BPTreeNode **root);
void insertNonFullBP(BPTreeNode *node, int key);
void splitChildBP(BPTreeNode *parent, int i, BPTreeNode *child);
```

- 时间复杂度：**O(log n)**
#### 查找操作：

```c
BPTreeNode* searchBP(BPTreeNode *node, int key) {
    int i = 0;
    while (!node->leaf)
        node = node->child[lowerBound(node->val, node->n, key)];
    for (i = 0; i < node->n; i++)
        if (node->val[i] == key) return node;
    return NULL;
}
```

- 时间复杂度：**O(log n)**
#### 范围查找：
```c
void rangeSearch(BPTreeNode *root, int low, int high) {
    BPTreeNode *node = root;
    while (!node->leaf)
        node = node->child[lowerBound(node->val, node->n, low)];

    while (node) {
        for (int i = 0; i < node->n; i++) {
            if (node->val[i] >= low && node->val[i] <= high)
                printf("%d ", node->val[i]);
        }
        node = node->next;
    }
}
```

- 时间复杂度：**O(log n + k)**（k 是结果个数）
---

##  三、总结对比

| 操作   | B-树      | B+树          |
| ---- | -------- | ------------ |
| 查找   | O(log n) | O(log n)     |
| 插入   | O(log n) | O(log n)     |
| 删除   | O(log n) | O(log n)     |
| 范围查询 | 差（不支持）   | 好（通过叶节点链表实现） |
