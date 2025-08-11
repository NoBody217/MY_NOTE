#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

vector<int> G[202020];
int idx[202020],f[202020],sz[202020],dep[202020];
int tim;

int dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    sz[x]=1;
    tim++;
    idx[x]=tim;
    f[x]=fa;
    for(auto y:G[x]){
        if(y==fa) continue;
        sz[x]+=dfs(y,x);    
    }
    return sz[x];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(n,0);
    int lca=1,ans=0;
    for(int i=1;i<=n;i++){
        while(lca<=0||!(idx[lca]<=idx[i]&&idx[i]<=idx[lca]+sz[lca]-1)){
            lca=f[lca];
        }
        ans+=dep[lca];
    }
    cout << ans << endl;
    return 0;
}