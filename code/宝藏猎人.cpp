#include<bits/stdc++.h>
using namespace std;

int p[30303];
int dp[30303][620];


int main(){
    int base=300;
    int n,d;
    cin >> n >> d ;
    for(int i=1;i<=n;i++){
        int tp;
        cin >> tp ;
        p[tp]+=1;
    }

    memset(dp,-0x3f3f,sizeof(dp));
    int ans=dp[d][base]=p[d]+p[0];

    for(int i=d+1;i<=30000;i++){
        for(int j=-300;j<=300;j++){
            if(d+j>0&&d+j<=i){
                dp[i][base+j]=max(dp[i][base+j],max(dp[i-(d+j)][base+j],max(dp[i-(d+j)][base+j-1],dp[i-(d+j)][base+j+1]))+p[i]);
            }
            ans=max(ans,dp[i][base+j]);
        }
    }
    cout << ans << endl;
    return 0;
}   