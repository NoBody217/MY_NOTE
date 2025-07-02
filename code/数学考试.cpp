#include<bits/stdc++.h>

using namespace std;

long long dp[302020];
long long a[302020];
int main(){
    int T;
    cin >> T ;
    while(T--){
        
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            dp[i]=-1e18;
            cin >> a[i];
            a[i]+=a[i-1];
        }

        for(int i=k;i<=n;i++){
            dp[i]=max(dp[i-1],a[i]-a[i-k]);
        }
        long long ans=-1e18;
        for(int i=n-k;i>=k;i--){
            ans=max(ans,dp[i]+(a[i+k]-a[i]));
        }

        // for(int i=1;i<=n;i++){
        //     cout << a[i] << ' ';
        // }
        // cout << endl;

        // for(int i=1;i<=n;i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;
        
        cout << ans << endl;
    }

    return 0;
}