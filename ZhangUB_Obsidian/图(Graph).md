# 图：非空有穷集，至少有一个点
## 各种定义
- 顶点：每个点
- 无向边，有向边()
- 无向图：所有边都是无向边
- 完全无向图：任意两个点之间都具有边，完全无向图有$\frac {n*(n-1)}{2}$条边
- 有向图：所有边都是有向边
- 完全有向图：同理
- 度：无向图顶点的边数
- 入度：**有向图**进入某一个点的边数
- 出度：**有向图**从某一个点出去的边数
- 边少的叫稀疏图，边多的叫稠密图
- 权：每个边具有的参数
- 带权图：也叫网络
- 路径长度：路径上边的条数
- 回路(环)：第一个顶点和最后一个顶点相同的路径
- 连通图：对图中的任何两个顶点a，b，如果都有路径可以从a->b,b->a，就是连通图
- 连通分量：无向图中的极大联通子图
	- 要是子图
	- 子图要是联通的
	- 联通子图含有极大顶点数，**再加一个点就不行**
	- 具有极大定点数的联通子图包含依附于这些顶点的所有边，**图里所有点的所有边都得在**
- 强连通图：对于有向图如果每一对点 都有相互到达的路径，就称该图为强连通图
- **生成树**：极小连通子图，含有n个顶点只有足以构成一棵树的n-1条边
	- 如果一个有向图恰有一个顶点入度为0，其余顶点入度为1，就是一个有向树
## 图的存储
### 邻接矩阵
- 一个二维数组描述边（边权）
- 建立的复杂度$O(n^{2})$
```c
int g[2000][2000];
```
### 邻接表
- 一个数组，数组的每个元素都是一个链表，链表的每个节点包含头的邻接结点在数组中的序号，这条边的权值，指针
	![[feff0262edb215215ba2c89349c8551d.png|450]]
```c
struct edge{
    int id;//边序号
    int nod;//邻接结点
    int wei;//边权
    struct edge *nxt;
};
typedef struct edge Edge;
typedef struct edge* Edgeptr;

Edgeptr g[1020];
//建
void budege(int idx, int a, int b ,int val) {
    Edgeptr p = (Edgeptr)malloc(sizeof(Edge));
    p->id = idx;
    p->nod = b;
    p->wei = val;
    p->nxt = NULL;
    if (g[a] == NULL) {
        g[a] = p;
    } else {
        Edgeptr q = g[a];
        while (q->nxt != NULL) {
            q = q->nxt;
        }
        q->nxt = p;
    }
}

```

## 图的遍历
- dfs+vis
	- 邻接矩阵$O(n^{2})$遍历，每个节点都要遍历矩阵的一行
	- 邻接表
```c
//邻接矩阵遍历：从s到e，输出路径上的所有点
int g[200][200];
int len,ans[200],vis[200];
void dfs(int s, int e)
{
	if (s == e)
	{
		for (int i = 0; i < len; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i <= n; i++)
	{
		if (g[s][i] != -1 && vis[i] != 1)
		{
			vis[i] = 1;
			ans[len++] = i;
			dfs(i, e);
			len--;
			vis[i] = 0;
		}
	}
}
```

```c
Edgeptr g[1020];
int ans[1020],vis[1020],len;
void dfs(int s,int e){
	if(s==e){
		for(int i=0;i<len;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		return ;
	}
	Edgeptr p=g[s];
	while(p!=NULL){
		if(!vis[p->nod]) {
			ans[len++]=p->id;
			dfs(p->nod,e);
			len--;
		}
		p = p->nxt;
	}
}
```
- bfs+vis
	- 邻接矩阵$O(n^{2})$同理dfs
	- 邻接表
## 最小生成树
- 求权值最小的生成树
### Prim算法
- 从某一个点开始，从所有邻接点中选择距离最小的节点
- 每次更新完点集后也更新可选的边集（可以暴力也可以堆）
#### 具体过程
- 从任意一个结点开始，将结点分为两类：已加入的，未加入的
- 每次从未加入的节点中，找一个与已加入的节点之间边权最小值最小的节点
- 加入这个节点，连上边权最小的边
#### 证明：说明在每一步时，存在一颗最小生成树包含已选的边集
- base：只有一个结点，显然成立
- 归纳：如果某一步成立，即当前边集F属于T这颗MST，接下来要加入边e
- 如果e属于T，则成立
- 否则考虑T+e这个集合，其中一定会有环在这个地方
- **对环上另一条边f考虑**
- 首先，f一定不小于e的权值，否则选择f不选择e
- 然后，f一定不大于e的权值，否则T-f+e就是更小的生成树
- 综上，唯一的可能是f=e，说明也是一颗最小生成树
```c
int dis[1020],vis[1020],path[1020];
int Prim() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    dis[0] = 0;
    int res = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, minv = 0x3f3f3f3f;
        for (int j = 0; j < n; ++j) {//找到距离最近的点u，距离minv
            if (!vis[j] && dis[j] < minv) {
                minv = dis[j];
                u = j;
            }
        }
        if (u == -1) return -1;
        vis[u] = 1;
        res += dis[u];
        cnt++;
        for (Edgeptr p = g[u]; p; p = p->nxt) {
            int v = p->nod;
            if (!vis[v] && p->wei < dis[v]) {
                dis[v] = p->wei;
                path[v] = p->id;
            }
        }
    }
    return res;
}
```
### Kruskal算法
- 由小到大加入边，如果某次加入会产生环，就扔掉这条边，直到加入了n-1条边

#### 证明：说明在每一步时产生的边集仍被某棵MST包含
- base：对于加入的第一条边，显然成立
- 归纳：加入某时刻边集F，令T为MST，考虑下一条加入的边e
- 如果e属于T，那一定成立
- 否则，T+e中一定有一个环，考虑环上不属于F的另一条边f(一定只有一条)
- 首先，f权值一定不小于e，不然先选取f
- 然后，f权值一定不大于e，不然T-f+e是更优的生成树
- 综上，e=f并且是另一棵最小生成树
```c
#define MAXN 1020
#define MAXM 20010
// === 并查集 ===
int fa[MAXN];
void init(int n) {
    for (int i = 0; i < n; ++i) fa[i] = i;
}
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}

typedef struct {
    int u, v, w, id;
} Edge;
// === 边排序：按权重升序 ===
int cmp_edge(const void* a, const void* b) {
    Edge* ea = (Edge*)a;
    Edge* eb = (Edge*)b;
    return ea->w - eb->w;
}
// === Kruskal 主函数 ===
int Kruskal(int n, int m, Edge edges[], int path[]) {
    qsort(edges, m, sizeof(Edge), cmp_edge);
    int res = 0, cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; ++i) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            merge(u, v);
            res += edges[i].w;
            path[cnt++] = edges[i].id;
        }
    }
    if (cnt != n - 1) return -1;  // 不连通
    return res;
}

```
## 最短路问题
- 单源最短路：从固定点出发，到所有其它点的最短路径
	- 无权：按递增顺序找各个顶点的最短路
		- 路径长度为0的顶点->路径长度为1的顶点
		- bfs改动即可
	- 有权:Dijkstra(无负权)
```c
//无权
int dis[1010],path[1010];
treeptr g[1010];
void bfs (int s,int e){
	memset(dis,-1,sizeof(dis));
	memset(path,-1,sizeof(path));
	int q[1010];
	int front=0,back=-1;
	q[++back]=s;
	while(back-front+1>0){
		int v=q[front++];
		treeptr tp=g[v];
		while(tp!=NULL){
			if(dis[tp->nod]!=-1)continue;
			q[++back]=g[tp->nod];
			dis[tp->nod]=dis[v];
			path[tp->nod]=v;
			q[++back]=tp->nod;
			tp=tp->nxt;
		}
	}
}
```
- 多源最短路：求任意两点之间最短路径
	- 对每个点都单源最短路跑一遍
	- floyd算法
		- 邻接矩阵爆搜
```c
int dp[1010][1010];
void floyd(){
	for(int i=0;i<n;i++){//初始化为边权
		for(int j=0;j<n;j++){
			dp[i][j]=g[i][j];
		}
	}
	for(int k=0;k<nn;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=(dp[i][k]+dp[k][j])<dp[i][j]?(dp[i][k]+dp[k][j]):dp[i][j];
			}
		}
	}
}
```
### Dijkstra
- 贪贪你的
- 维护一个dis数组记录距离，维护一个vis数组记录每个点有没有被访问过
- dis全部初始化为INF，起https://www.bilibili.com/?spm_id_from=333.337.0.0点初始化为0
#### 具体过程
- 初始化
- 从未确定最短路的集合中去除最短路最小的结点u，移入已确定最短路的集合中
- 对u的所有邻接点k做松弛
	- 松弛操作：看起点到k的当前最小距离距离是否小于起点到u在加上u到k的距离
```c
#define MAXN 1000  // 根据实际需求调整最大节点数
#define INF 0x3f3f3f3f
typedef struct Edge {
    int v;
    int w;
    struct Edge* next;
} Edge;
Edge* graph[MAXN];  // 邻接表存储图
int dis[MAXN];      // 存储最短距离
int vis[MAXN];      // 标记节点是否已访问

// 添加边到邻接表
void adde(int u, int v, int w) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->v = v;
    new_edge->w = w;
    new_edge->next = graph[u];
    graph[u] = new_edge;
}
void dijkstra(int n, int s) {//总结点数，起点
	//O(n^3)
    // 初始化距离数组和访问标记数组
    memset(dis, 0x3f, (n + 1) * sizeof(int));
    memset(vis, 0, (n + 1) * sizeof(int));
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = 0, mind = INF;
        // 找到当前未访问的最小距离节点
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < mind) {
                u = j;
                mind = dis[j];
            }
        }
        if (mind == INF) break;  // 所有可达节点已处理完
        vis[u] = 1;
        // 遍历所有邻接边进行松弛操作
        Edge* curr = graph[u];
        while (curr != NULL) {//我已经在u了，看看经过u到别的地方，是否比原来的方式好
            int v = curr->v, w = curr->w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
            curr = curr->next;
        }
    }
}
```