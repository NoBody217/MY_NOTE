#include<bits/stdc++.h>
// #define int long long
using namespace std;

int val[15][15];
int dp[1<<13];
/**
 * dp[i]表示st状态下最大能量
 * dp[i|1<<j]=dp[i]+val[j][i]
 * 1表示消失了，0表示还没消失
 */
int n;

int deal(int st){
    if(st==0) return 0;
    if(dp[st]>=0) return dp[st];
    dp[st]=0;
    for(int i=1;i<=n;i++){
        if((st>>(i-1)&1)==0) continue;
        for(int j=1;j<=n;j++){
            if(i==j||(st>>(j-1)&1)==0) continue;
            int st1=st-(1<<(i-1));
            dp[st]=max(dp[st],deal(st1)+val[j][i]);
        }
    }
    return dp[st];
}

signed main(){
    while(1){
        memset(dp,-1,sizeof(dp));
        memset(val,0,sizeof(val));
        cin >> n ;
        if(n==0)break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> val[i][j] ;
            }
        }

        cout << deal((1<<n)-1) << endl;
    }
    return 0;
}