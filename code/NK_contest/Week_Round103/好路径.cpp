#include<bits/stdc++.h>
using namespace std;


vector<int> G[101010];
vector<int> f(101010);
vector<int> vis(1<<22);
string v;

void dfs(int x,int fa){
    f[x]=fa;
    for(auto i:G[x]){
        if(i==fa)continue;
        dfs(i,x);
    }
    int dep=0;
    int s1=0,s2=0;
    while(dep<=21&&x!=0){
        s1=(s1<<1)+(v[x]-'0');
        s2=s2+((v[x]-'0')<<dep);
        x=f[x];
        dep++;
        vis[s1]=1;vis[s2]=1;
    }    
}
int main(){
    int n,q;
    cin >> n >> q;
    cin >> v;
    v=' '+v;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        cout << (vis[x]?"YES":"NO") << endl;
    }
    return 0;
}