- 好复杂的一个题
# 题意
- n个结点，形成一棵根为1的树
- k个帮派，每个帮派会控制一些结点
- 帮派可能结盟，单个帮派也可自己结盟，结盟后任意两个被控制的结点之间的路径都被联盟控制
- Q次询问，每次询问给出首都V和结盟的帮派，只需要考虑结盟的帮派
- 每次询问回答首都V到最近的被控制的城市的距离
# 思路
- 对于结盟：任何两个点u,v结盟后所控制的点是lca(u,v)到u和v的路径上的所有点，多个点结盟就是lca(all_node)到每一个点的路径上的所有点
- 对于每次询问：共有分为三种情况，记LCA为询问中所有的控制点的lca
    - V不在LCA子树中，则V一定不被控制，此时dis就是V和LCA在树上的距离： $ans=dis[V]+dis[LCA]-2*dis[lca(V,LCA)]$
        - 判断在不在LCA子树中直接求一个lca(V,LCA)看结果是不是LCA就行
    - V在LCA子树中，如果V是被控制的点，则V和**V之后的最近的直接控制点**的公共祖先一定是V
    - V在LCA的子树中，但V不是被控制的点，则V和**最近的直接控制点**的公共祖先一定是V
    - 对于最近的直接控制点怎么找：
        - 线性查找：在dfn序上维护一个左侧最近控制帮派，维护一个右侧最近控制帮派，跳跃查找，有可能会退化到O(k)最终会TLE
        - 二分查找：每个帮派按照dfn序做一个升序排序，对于所有被考虑的帮派，`lower_bound`找第一个大于等于V的被控制城市，如果位置合法，就和当前以及上一个都求一个ans，ans不断取min
# 代码
```cpp
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int>G[505050];//存图
vector<int>a[505050];//存帮派
int dep[505050],lca[505050];//每个点深度，每个帮派的lca
int dfn[505050];//点编号->dfn
int b[1010101];//欧拉序
int ba[505050],first[505050];//dfn->点编号，第一次出现
int f[1010101][20];//st表
// int vis[505050];//帮派是否被选中，线性查找用
// int fa[505050];//每个结点所属的帮派，线性查找用
// int pre[1010101],sfx[1010101];//前驱和后继，线性查找用
int tim,cnt;

void rmq_st(){
    for(int i=1;i<=cnt;i++) f[i][0]=b[i];
    int t=(int)log2(1.0*cnt);
    for(int j=1;j<=t;j++){
        int m=cnt-(1<<j)+1;
        for(int i=1;i<=m;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);        
    }
}

int rmq_find(int l,int r){
    int k=(int)(log2(1.0*(r-l+1)));
    return min(f[l][k],f[r-(1<<k)+1][k]);
}


int gtlca(int l,int r){
    if(first[r]<first[l]) swap(l,r);
    int k=rmq_find(first[l],first[r]);
    return ba[k];
}

void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    dfn[x]=++tim;
    ba[tim]=x;
    b[++cnt]=dfn[x];
    first[x]=cnt;
    for(auto i:G[x]){
        if(i==fa) continue;
        dfs(i,x);
        b[++cnt]=dfn[x];
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1,0);
    rmq_st();

    int k;
    cin >> k;
    for(int i=1;i<=k;i++){
        int cnt;
        cin >> cnt;
        for(int j=0;j<cnt;j++){
            int tmp;
            cin >> tmp;
            fa[tmp]=i;
            if(j==0) lca[i]=tmp;
            else lca[i]=gtlca(lca[i],tmp);
            a[i].push_back(dfn[tmp]);//存dfn用于二分找最小
        }
    }
    for(int i=1;i<=k;i++) sort(a[i].begin(),a[i].end());

    // int p=0;
    // for(int i=1;i<=tim;i++){
    //     if(fa[ba[i]]!=0) p=i;
    //     pre[i]=p;
    // }
    // int s=tim+1;
    // for(int i=tim;i>=1;i--){
    //     if(fa[ba[i]]!=0) s=i;
    //     sfx[i]=s;
    // }

    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int V,t;
        cin >> V >> t;
        int LCA=0;
        vector<int> use;
        for(int j=1;j<=t;j++){
            int tmp;
            cin >> tmp;
            if(j==1) LCA=lca[tmp];
            else LCA=gtlca(LCA,lca[tmp]);
            // vis[tmp]=i;
            use.push_back(tmp);
        }
        int L=gtlca(V,LCA);
        if(L!=LCA){
            cout << dep[LCA]+dep[V]-2*dep[L] << endl;
        }else{
            int ans=INT_MAX;

            for(auto k:use){
                auto p=lower_bound(a[k].begin(),a[k].end(),dfn[V]);
                int pos=p-a[k].begin();
                if(p<a[k].end()){
                    ans=min(ans,dep[V]-dep[gtlca(V,ba[a[k][pos]])]);
                }
                if(p>a[k].begin()){
                    ans=min(ans,dep[V]-dep[gtlca(V,ba[a[k][pos-1]])]);
                }
            }

            // int l,r;
            // l=r=dfn[V];
            // while(vis[fa[ba[l]]]!=i&&l!=0) l=pre[l];
            // while(vis[fa[ba[r]]]!=i&&r!=tim+1) r=sfx[r];
            // if(l!=0) ans=min(ans,dep[V]-dep[gtlca(V,ba[l])]);
            // if(r!=tim+1) ans=min(ans,dep[V]-dep[gtlca(V,ba[r])]);
            cout << ans << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
```