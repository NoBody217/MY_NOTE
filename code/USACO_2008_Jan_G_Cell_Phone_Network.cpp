#include<bits/stdc++.h>

using namespace std;

/**
 * 最小支配集，每个点覆盖相邻点，覆盖所有点
 * 考虑每个点被覆盖的可能性，要么靠自己，要么靠父亲，要么靠儿子
 * dp[i][0/1/2]
 * 自己：dp[i][0]=sum(min(dp[u][0],dp[u][1],dp[u][2]))+1
 * 父亲：dp[i][1]=sum(min(dp[u][0],dp[u][2]))
 * 儿子：dp[i][2]=sum(min(dp[u][0],dp[u][2]))
 * 同时维护min(dp[u][0]-dp[u][2])如果最终结果大于0,说明全都选的dp[u][0]
 * 需要加上最小的increasing，如果结果小于0，说明已经有一个被选了，不用管
 */


int dp[101010][3];
vector<int> a[101010];

void dfs(int x,int fa){
    dp[x][0]=1;
    int inc=0x3f3f3f3f;
    for(auto i :a[x]){
        if(i==fa)continue;
        dfs(i,x);
        dp[x][0]+=min(dp[i][0],min(dp[i][1],dp[i][2]));
        dp[x][1]+=min(dp[i][0],dp[i][2]);
        dp[x][2]+=min(dp[i][0],dp[i][2]);
        inc=min(dp[i][0]-dp[i][2],inc);
    }
    if(inc>0) dp[x][2]+=inc;
}

int main(){
    memset(dp,0,sizeof(dp));
    int n;
    cin >> n ;
    for(int i=1;i<n;i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    cout << min(dp[1][0],dp[1][2]);
    return 0;
}