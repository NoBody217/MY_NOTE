#动态规划 #树状dp #dfs 
# 题意
- 对于一棵树，我们希望找到一个点，使得删除这个点之后，最大子树的结点数最小
- 以边的形式输入，输出被删除的点的编号和删除后最大子树的结点数
# 思路
* 考虑用无根树描述，对于树的某一个结点，删掉后，整棵树变为两部分
	* 这个结点的父亲所属的树
	* 这个结点的若干子树
* 故另$f[i]$表示删除这个点后最大子树结点数，$tol[i]$表示这个点除了父亲以外的子树的总结点数，则$n-tol[i]$就是祖先部分的结点数
* 得到$f[i]=max(tol[u],n-tol[i])$,u是i的每一个儿子，$tol[i]=sum(tol[u])+1$
* 所求答案为所有$f[i]$中最小的一个
# 代码
```cpp
#include<bits/stdc++.h>
#define maxn 1024
using namespace std;
int n;
int tol[maxn],f[maxn];
vector<int> tree[maxn];
void dfs(int x,int fa){
    int tolu=-0x3f3f3f3f;
    tol[x]=1;
    for(int i=0;i<tree[x].size();i++){
        int son=tree[x][i];
        if(son==fa) continue;
        dfs(son,x);
        tol[x]+=tol[son];
        tolu=max(tolu,tol[son]);
    }
    f[x]=max(n-tol[x],tolu);
    // cout << x << ' ' << fa << ' ' << tolu << ' ' << tol[x] << endl ;
}

int main(){

    while(cin >> n){
        for(int i=0;i<maxn;i++){
            tree[i].clear();
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b ;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        dfs(1,0);
        int idx=0,ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            if(f[i]<ans){
                idx=i;
                ans=f[i];
            }
        }
        cout << idx << ' ' << ans << endl ;
    }
    return 0;
}
```