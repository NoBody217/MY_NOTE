#include<bits/stdc++.h>
#define maxn 1024
using namespace std;
/**
 * 考虑用无根树描述
 * 对于树的某一个结点，删掉后，出现若干棵子树
 * 故f[i]表示删除这个点后最大子树结点数
 * tol[i]表示这个点除了父亲以外的子树的总结点数
 * f[i]=max(tol[u],n-tol[i]),u是i的每一个儿子
 * tol[i]=sum(tol[u])+1
 */
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