#include<bits/stdc++.h>

using namespace std;



/**
 * dp[i]=dp[i-1]+dp[i-2]
 */
vector<long long> dp(100);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    dp[1]=1,dp[2]=2;
    for(int i=3;i<=80;i++) dp[i]=dp[i-1]+dp[i-2];

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n' ;
    }
    
    return 0;
}