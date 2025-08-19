# LCA-最近公共祖先
## Tarjan——dfs+并查集
- 离线算法，如果下一次询问和上一次有关就没法离线了
- dfs+并查集
- 并查集：每个点初始化祖先为自己
- 访问所有儿子，当回溯的时候把祖先改为fa
- 对于查询LCA(u,v)，如果u已经被访问，v没被访问，LCA(u,v)=find(u)
```cpp
int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
void merge(int x,int y){ fa[find(x)]=find(y); }

void dfs(int x,int fa){
    for(auto i:G[x]){
        if(x==fa) continue;
        dfs(i,x);
        merge(i,x);
    }
    vis[x]=1;
    for(int i=0;i<n;i++){
        if(vis[i]&&que[x][i]){
            lca[i][x]=lca[x][i]=find(i);
            que[x][i]=que[i][x]=0;
        }
    }
}
```
## dfs序+st表——通过dfs序转化为RMQ
### 通过dfs序转化为RMQ
- dfs，按照顺序将遍历到的节点记录，经过一次记录一次，得到一个长度为2N-1的序列，称为欧拉序列
- 记录u在序列中第一次出现的位置pos\[u]，pos\[u]和pos\[v]之间深度最小的点就是LCA
- LCA(u,v)=RMQ(dfn\[u],dfn\[v])
- **使用dfn而不使用深度来避免同深度多个点不好找的问题**
```cpp
void dfs(int x,int fa){
    tim++;
    b[++cnt]=tim;//欧拉序列，用于RMQ
    f[tim]=x;//编号映射
    first[x]=cnt;
    for(auto i:G[x]){
        if(i==fa)continue;
        dfs(i,x);
        b[++cnt]=x;
    }
}

int LCA(int a,int b){
    if(first[a]>first[b]) swap(a,b);
    int k=rmq_find(first[a],first[b]);
    return f[k];
}
```

## 树上倍增——倍增法在树上应用
- F\[i]\[j]表示i向上2^j层的祖先是哪个点
- F\[i]\[0]=fa\[i]，F\[i]\[1]=yeye\[i]，F\[i]\[2]=爷爷的爷爷\[i]
- F\[i]\[2]=F\[F\[i]\[1]][1]，F\[i]\[1]=F\[F\[i]\[0]]\[0]
- F\[i]\[j]=F\[F\[i]\[j-1]]\[j-1]
- 先维护F，然后维护深度
- 对于要求lca的两个点，先跳到统一深度
- 然后同步上跳一个极大层2^k，使得相同
- 然后回去改为跳2^k-1，如果不同就继续上跳2^k-2直到上跳一层就相同，相同的点就是lca
- 如果相同就回去改为跳2^k-2
```cpp
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    F[x][0]=fa;
    for(int i=1;(1<<i)<=dep[x];i++)
        F[x][i]=F[F[x][i-1]][i-1];
    for(auto i:G[x]){
        if(i==x) continue;
        dfs(i,x);
    }
}

int LCA(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=dep[b]-dep[a],j=0;i>0;i>>=1;j++){
        if(i&1) 
            b=F[b][j]
    }
    if(a==b) return a;
    int k;
    for(k=0;(1<<k)<=dep[a];k++);
    for(;k>=0;k--){
        if(F[a][k]==F[b][k]) continue;
        else{
            a=F[a][k];
            b=F[b][k];
        }
    }
    return F[a][0];
}
```
## 树链剖分

# RMQ
## 朴素暴力
## 线段树
- $O(nlogn)$ 预处理
- $O(logn)$ 查询
- 可修改
## ST
- $O(nlogn)$ 预处理
- $O(1)$ 查询
- 可修改
- 二维数组f\[i]\[j]记录区间\[i,i+2^j-1]中的最值
- 其中f\[i]\[0]=a\[i]
- 动态规划转移方程：$f[i][j]=min(f[i][j-1],f[i+2^{j-1}][j-1])$
```cpp
void rmq_st(){
    for(int i=0;i<=n;i++) dp[i][0]=b[i];
    int m=(int)(log(1.0*n)/log(2.0));
    for(int j=1;j<=m;j++){
        int t=n-(1<<j)+1;
        for(int i=1;i<=t;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
}
int rmq_find(int l,int r){
    int k=(int)(log(1.0*(r-l+1))/log(2.0));
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

```
## 笛卡尔树+正负MQ
- $O(n)$ 预处理
- $O(1)$ 查询
# 三种dfs序
# DFN序
- 维护时间戳，记录最大时间戳or子树大小
- 将一棵树变为若干区间，一段区间代表一棵树
- 可以将树上问题变为线性问题
# 欧拉序
- 记录经过点的序列，每次经过都记录
# DFS序
- 入栈和出栈记录，每个点记录两遍