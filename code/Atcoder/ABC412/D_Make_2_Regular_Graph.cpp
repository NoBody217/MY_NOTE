#include<bits/stdc++.h>

using namespace std;

int n,m,res=1000;
int p[10];
bool G[10][10],K[10][10],vis[10];
void dfs(int depth){
    if(depth>n){
        memset(K,false,sizeof(K));
        for(int i=1;i<=n;i++){
            K[i][p[i]]=K[p[i]][i]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans+=K[i][j]^G[i][j];
            }
        }
        res=min(res,ans);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&depth!=i&&!(depth>i&&p[i]==depth)){
            vis[i]=1;
            p[depth]=i;
            dfs(depth+1);
            vis[i]=0;
        }
    }
}
int main(){

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a][b]=G[b][a]=true;
    }
    dfs(1);
    cout << res << endl;
    
}