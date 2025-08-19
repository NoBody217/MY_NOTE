#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll dp[400][400];
vector<int> G[500];
const int p=1e9+7;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=(dp[i-1][j-1]*(k-(j-1)))%p+dp[i-1][j]%p;
        }
    }
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+dp[n][i])%p;
    }
    cout << ans << endl;
    return 0;
}