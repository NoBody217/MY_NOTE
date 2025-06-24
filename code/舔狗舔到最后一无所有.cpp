#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

vector<long long> dp(101010);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    dp[1]=3;dp[2]=9;
    for(int i=3;i<101010;i++)
        dp[i]=(dp[i-1]+dp[i-2])*2%mod;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}