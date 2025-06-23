#include<bits/stdc++.h>
using namespace std;

const int N =600;
int a[N],sum[N];
int dp1[N][N];
int dp2[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(dp2,0x3f3f3f3f,sizeof(dp2));
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i+n]=a[i];
        dp2[i][i]=0;
        dp2[i+n][i+n]=0;
    }

    for(int i=1;i<=2*n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=1,r=l+len-1;r<=2*n;l++,r++){
            for(int k=l;k<=r-1;k++){
                dp1[l][r]=max(dp1[l][r],dp1[l][k]+dp1[k+1][r]+sum[r]-sum[l-1]);
                dp2[l][r]=min(dp2[l][r],dp2[l][k]+dp2[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    int ans_max=0,ans_min=INT_MAX;
    for(int i=1;i+n-1<=2*n;i++){
        ans_max=max(ans_max,dp1[i][i+n-1]);
        ans_min=min(ans_min,dp2[i][i+n-1]);
    }
    // for(int i=1;i<=2*n;i++){
    //     for(int j=1;j<=2*n;j++){
    //         cout << dp2[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << ans_min << endl;
    cout << ans_max << endl;



    return 0;
}