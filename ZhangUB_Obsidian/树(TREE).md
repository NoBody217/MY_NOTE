# 树
## 定义
- n个结点构成的有限集合
- 树有一个**根**（root）
- 其余结点可分为若干个互不相交的有限集，每个集合本身是一颗树，称为原来的树的**子树**
## 相关术语
- 结点的度（degree）：结点的子树个数
- 树的度：最大的degree
- 叶结点：度为0的点
- 父节点：有子树的结点是其子树的根节点的父节点
- 子节点：字面意思
- 兄弟结点：同一父亲
- 路径和路径长度：一个结点到另一个结点包含的所有结点|结点个数即为长度
- 祖先结点：从根到该结点的所有结点均为该结点的祖先
- 子孙结点：某一结点的子树的所有结点，都是该结点的子孙
- 层次：字面意思
- 深度：最大层次
## 表示
- 链式结构（空间浪费）每个结点包含一个数值域，一个指针域，指针域的大小为树的度
- 儿子-兄弟表示法：每个结点记录自己的长子和第一个弟弟
	![[90a52764-fda0-4d69-b725-f7e58fc50679.png|450]]
- 二叉树：儿子兄弟表示法旋转 $45^{。}$得到
	![[b659e268-608a-45a7-97cb-60a2bc53c638.png|450]]
- 
## 性质
- n个结点的树有n-1条边（除了根每个结点均有一个边连向自己的父亲）
## 二叉树
- 有左右子树之分的度为2的树
### 满二叉树
- 除了叶结点每个结点都是两个儿子，且叶结点都在同一层
### 完全二叉树
- 满二叉树最后一层按顺序抛掉若干个结点
### 二叉树性质
- 二叉树第i层最大结点数为：$2^{i-1}$
- 深度为k的二叉树最多结点数：$2^{k}-1$ (二进制拆分)
- 非空二叉树结点数：若$n_{0}$表示叶结点个数，$n_{1}$是度为1的结点个数，$n_{2}$是度为2的结点个数，总结点数为$n_{0}+n_{1}+n_{2}$，且$n_{0}=n_{2}+1$
	- 证明如下
		对于总结点数，易知边的个数为$n_{0}+n_{1}+n_{2}-1$
		同时考虑每个结点贡献的向下的边的个数，得到总边数为$0*n_{0}+1*n_{1}+2*n_{2}$
		上下两式相等，联立即可得证
### 二叉树操作
- 判空
- 建树
- 遍历：先序遍历（根左右），中序遍历（左根右），后序遍历（左右根），层次遍历
	前三种依靠递归实现，层次遍历依靠队列实现
### 二叉树存储
#### 顺序结构
- 完全二叉树(选定一种表示就别换了)：
	- 根为0：第i个结点的儿子是2\*i+1和2\*i+2，第i个结点的父亲是(i+1)/2
	- 根为1：第i个结点的儿子是2\*i和2\*i+1，第i个结点的父亲是i/2
- 一般二叉树：也可以表示成完全二叉树，会造成一定的空间浪费
#### 链式结构
```c
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node tree;
typedef struct node* treeptr;
```
### 二叉树遍历（可递归可非递归）
- 接下来的代码均是递归实现思路，非递归实现基于堆栈（因为递归的本质就是堆栈），不太需要，想看可以自己搜索
#### 先序遍历
```c
void pre(treeptr BT){
	if(BT){
		printf("%d",BT->data);
		pre(BT->left);
		pre(BT->right);
	}
}
```
#### 中序遍历
```c
void mid(treeptr BT){
	if(BT){
		mid(BT->left);
		printf("%d",BT->data);
		mid(BT->right);
	}
}
```
#### 后序遍历
```c
void post(treeptr BT){
	if(BT){
		post(BT->left);
		post(BT->right);
		printf("%d",BT->data);
	}
}
```
#### 顺序遍历图示
![[e4012c41-3c5e-4d5d-bf5b-6ef0bf7bd1f5.png|450]]
#### 层次遍历（数组实现较为舒适）
- BFS
- 根入队
- 循环直至队列为空
	访问队首，出队，将他的儿子放入队尾
	出队顺序就是层次遍历顺序
```c
//链表实现
const int N =5000;
void level(treeptr BT){
	treeptr que[N];
	int front = 0,back = -1;
	que[++back]=BT;
	while(back-front+1!=0){
		treeptr tp=que[front++];
		printf("%d\n",tp->data);
		if(tp->left) que[++back]=tp->left;
		if(tp->right) que[++back]=tp->right;
	}
}
```
#### 应用
- 输出叶子节点
```c
void pre(treeptr BT){
	if(BT){
		if(!BT->left&&!BT->right) printf("%d",BT->data);
		pre(BT->left);
		pre(BT->right);
	}
}
```
- 表达式树得到前缀，中缀，后缀表达式
	避免中缀错误：在遍历左子树前加一个左括号，遍历完右子树后加一个右括号
	![[ffea169b-4208-4655-a7dd-ebb399994c48.png|450]]
- 求二叉树高度
```c
void getH(treeptr BT){
	if(BT){
		int Hl=getH(BT->left);
		int Hr=getH(BT->right);
		return Hl>Hr?Hl+1:Hr+1;
	}
	return 0;
}
```
- 由两种遍历顺序确定二叉树
	- 中序+任意一种
	- 中序+先序
		先序的第一个是根
		通过根+中序确定左子树和右子树
		在先序中找到左子树，第一个为左子树根，重复上述过程
		在先序中找到右子树，第一个为右子树根，重复上述过程
		递归实现
	- 中序+后续 类似
### 二叉搜索树(Binary Search Tree)
- 一颗满足如下性质的二叉树：
	- 非空左子树的所有值小于根的值
	- 非空右子树的所有值大于根的值
	- 左右子树均为二叉搜索树
- 二叉搜索树主要有如下操作：搜索（在整棵树上查找元素x，返回其idx或者地址），寻找最小元素（从二叉搜索树中寻找最小元素，返回其idx或地址），寻找最大元素（从二叉搜索树中寻找最大元素，返回其idx或地址），**插入和删除**
#### 查找特定元素
- 从根节点开始，如果树为空，返回NULL
- 若非空，比较根节点值（x）和查找值（find）
	- 如果x>find，在左子树中搜索
	- 如果x<find，在右子树中搜索
	- 如果相等，返回根节点地址
```c
//指针version
treeptr Pfind(int find,treeptr BST){
	if(!BST) return NULL;
	if(find>BST->data) return Pfind(find,BST->right);
	else if(find<BST->data) return Pfind(find,BST->left);
	else if(find==BST->data) return BST;
}
//非递归实现
treeptr Pfind(int find,treeptr BST){
	while(BST){
		if(find>BST->data) BST=BST->right;
		else if(find<BST->data) BST=BST->left;
		else if(find==BST->data) return BST;
	}
	return NULL;

}
```

```c
//数组version
int BST [202020];//需要初始化
//memset(BST,-0x3f3f3f3f,sizeof(BST));
int Pfind(int find,int pos){//pos为搜索位置一般传1
	if(BST[pos]==-0x3f3f3f3f) return -1;
	if(find>BST[pos]) return Pfind(find,pos*2+1);
	else if(find<BST[pos]) return Pfind(find,pos*2);
	else if(find==BST[pos]) return pos;
}
//非递归实现
int Pfind(int find,int pos){//pos为搜索位置一般传1
	while(BST[pos]!=-0x3f3f3f3f){
		if(find>BST[pos]) pos=pos*2+1;
		else if(find<BST[pos]) pos=pos*2;
		else if(find==BST[pos]) return pos;
	}
	return -1;
}
```

#### 查找最大|最小
- 最大元素一定在最右分支的端结点上，最小元素一定在最左分支的端结点上
```c
//指针version，min就是right改为left
treeptr findmax(treeptr BST){
	if(!BST) return NULL;
	else if(!BST->right) return BST;
	else return findmin(BST->right);
}
//非递归实现
treeptr findmax(treeptr BST){
	if(BST){//确保非空
		while(BST->right) BST=BST->right;
	}
	return BST;
}
```

```c
//数组version
int BST [202020];//需要初始化
//memset(BST,-0x3f3f3f3f,sizeof(BST));
int findmax(int pos){
	if(BST[pos]==-0x3f3f3f3f) return -1;
	else if(BST[pos*2+1]==-0x3f3f3f3f) return pos;
	else return findmax(pos*2+1);
}
//非递归实现
int findmax(int pos){
	if(BST[pos]!=-0x3f3f3f3f){
		while(BST[pos*2+1]!=-0x3f3f3f3f) pos=pos*2+1;
	}
	return pos;
}
```
#### 插入
- 关键在于找到位置，使用类似查找的方法
```c
//指针
treeptr insert(int x,treeptr BST){//返回的是根结点
	if(!BST){//如果是空的就从头开始建
		BST=malloc(sizeof(tree));
		BST->data=x;
		BST->left=BST->right=NULL;
	}else{//递归查找
		if(x<BST->data) BST->left=insert(x,BST->left);
		else if(x>BST->data) BST->right=insert(x,BST->right);
		else{
			//如果x已经存在，就什么都不做
		}
	}
	return BST;
}
```

```c
//数组
void insert(int x,int pos){
	if(BST[pos]==-0x3f3f3f3f) BST[pos]=x;
	else{
		if(x<BST[pos]) insert(x,pos*2);
		else if(x>BST[pos]) insert(x,pos*2+1);
		//存在就什么都不做
	}
}
```
#### 删除
- 如果是叶结点，直接删除，将其父节点的指针指向NULL
- 如果删除的结点只有一个孩子结点，把该结点的父亲的指针指向儿子
- 如果删除的结点有左右子树，要用另一结点替代被删除的结点，取右子树最小元素，或左子树最大元素来替代（因为这两个结点一定不是有两个子树的结点）
```c
//指针version
treeptr del(int x,treeptr BST){
	if(!BST) printf("未找到要删除元素");
	else if(x<BST->data) BST->left=del(x,BST->left);//左子树递归删除
	else if(x>BST->data) BST->right=del(x,BST->right);//右子树递归删除
	else{//找到了
		treeptr tmp;
		if(BST->left&&BST->right){
			tmp=findmin(BST->right);//用右子树最小来填充
			BST->data=tmp->data;
			BST->right=del(BST->data,BST->right);//删除右子树最小
		}else{//有一个子节点或者没有子节点
			tmp=BST;//指向被删结点
			if(!BST->left) BST=BST->right;
			else if(!BST->right) BST=BST->left;
			free(tmp);	
		}
	}
	return BST;
}
```

```c
//数组version
void del(int x,int pos){
	if(BST[pos]==-0x3f3f3f3f) printf("未找到");
	else if(x<BST[pos]) del(x,pos*2);
	else if(x>BST[pos]) del(x,pos*2+1);
	else{//找到了
		int tmp;
		if(BST[pos*2]!=-0x3f3f3f3f&&BST[pos*2+1]!=-0x3f3f3f3f){
			tmp=findmin(pos*2+1);
			BST[pos]=BST[tmp];
			del(BST[tmp],pos*2+1);
		}else{
			if(BST[pos*2]==-0x3f3f3f3f){
				BST[pos]=BST[pos*2+1];
				BST[pos*2+1]=-0x3f3f3f3f;
			}
			else if(BST[pos*2+1]==-0x3f3f3f3f){
				BST[pos]=BST[pos*2];
				BST[pos*2]=-0x3f3f3f3f;
			}
		}
	}
}
```
#### 不重要-平衡二叉树(AVL树)
- 搜索树的插入顺序不同，会导致不同的深度和不同的平均查找长度(ASL)
- 平衡因子(BF)：$BF=h_{l}-h{r}$ 
- 平衡二叉树就是左右子树高度差不超过1，即 BF小于等于1
- 平衡二叉树的高度最高为$log_{2}n$
-  平衡二叉树的调整-RR,LL,RL,LR
## 堆
- 一种特殊二叉树，每个结点的值大于或小于其每个子节点的值
- 完全平衡，最后一层的叶子节点靠左
### 堆构造
- insert(x)
	- 把x放入堆的末尾，只要x不是根且x>parent(x)
		- swap(x,parent(x))
- delete()//删除并获取堆顶
	- 从根节点提取元素，把最后一个叶结点中的元素放到根的位置
	- 删除该叶结点p
	- while(p不是叶结点且p<他的任何子节点)
		- p和他最大子节点交换
## 表达式树，直接见代码即可
## 哈夫曼树(歪脖子树)
- 对于每个结点具有权值，权值\*点到根距离得到带权路径长度
- 只有叶结点有权值且路径长度最小的二叉树就是哈夫曼树
- 构造方式：将每个结点视作一棵树，构建一个树林，每次取权值最小的两颗二叉树合并成新的二叉树的，直到只有一颗二叉树