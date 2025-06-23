#include<bits/stdc++.h>
using namespace std;

/**
 * dp[i][j]表示i包含j个点(边)
 * dp[i][j]=dp[T[i].l][k]+dp[T[i].r][j-1-k];
 */


typedef struct node{
    int val;
    int l,r;
}tree;
tree T[200];
vector<int> g[150];
int v[150][150];
int dp[150][150];
int n,q;

void push_down(int x,int fa){
    for(auto i : g[x]){
        if(i==fa)continue;

        if(T[x].l==0) T[x].l=i;
        else T[x].r=i;

        T[i].val=v[x][i];            
        push_down(i,x);
    }
}


int dfs(int x,int rst){
    if(x==0) return 0;
    if(dp[x][rst]!=0) return dp[x][rst];
    for(int i=0;i<rst;i++){
        dp[x][rst]=max(dp[x][rst],dfs(T[x].l,i)+dfs(T[x].r,rst-1-i)+T[x].val);
    }
    return dp[x][rst];
}

int main(){
    cin >> n >> q;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c ;
        g[a].push_back(b);
        g[b].push_back(a);
        v[a][b]=v[b][a]=c;
    }
    push_down(1,0);
    cout << dfs(1,q+1) << endl ;    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=q;j++){
            cout << i << ' ' << j << ' ' <<  dp[i][j] << endl ;
        }
        // cout << i << ' ' << T[i].val << ' ' << T[i].l << ' ' << T[i].r << endl;
    }

    return 0;
}