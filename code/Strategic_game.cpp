#include<bits/stdc++.h>
using namespace std;

/**
 * dp[i][0/1];表示自己不选，自己选
 * dp[i][1]=sum(min(dp[u][0],dp[u][1])+1;
 * dp[i][0]=sum(dp[u][1]);
 */

vector <int> son[2000];
int dp[2000][2];
void dfs(int x,int fa){
    dp[x][1]=1;
    dp[x][0]=0;
    for(auto i : son[x]){
        if(i==fa) continue;
        dfs(i,x);
        dp[x][1]+=min(dp[i][0],dp[i][1]);
        dp[x][0]+=dp[i][1];
    }
}

int main(){
    int n ;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<2000;i++){
            son[i].clear();
        }
        int x,y,cnt ;
        for(int j=0;j<n;j++){
            scanf("%d:(%d)",&x,&cnt);
            for(int i=0;i<cnt;i++){
                scanf("%d",&y);
                son[x].push_back(y);
                son[y].push_back(x);
            }            
        }
        dfs(0,-1);
        cout << min(dp[0][0],dp[0][1]) << endl;
    }
    return 0;
}