#include<bits/stdc++.h>

using namespace std;

int n,q;
vector<int> g[120];
vector<int> apple[120];
int dp[300][300];
void dfs(int x,int fa){
    dp[x][0]=0;
    for(int id=0;id<g[x].size();id++){
        int i=g[x][id];
        if(i==fa) continue;
        dfs(i,x);
        for(int j=q;j>=0;j--){
            for(int k=0;k<j;k++){
                dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[i][k]+apple[x][id]);
            }
        }
    }

}

int main(){
    cin >> n >> q ;
    for(int i=1;i<n;i++){
        int x,y,val;
        cin >> x >> y >> val;
        g[x].push_back(y);
        g[y].push_back(x);
        apple[x].push_back(val);
        apple[y].push_back(val);
    }
    dfs(1,0);
    cout << dp[1][q];
    return 0;
}