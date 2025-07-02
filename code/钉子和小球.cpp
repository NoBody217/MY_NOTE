#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100][100];
int dp[100][100];

signed main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char tp;
            cin >> tp;
            a[i][j]=(tp=='*');
        }
    }

    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i][j]){
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j]+=dp[i][j];
            }else{
                dp[i+2][j+1]+=4*dp[i][j];
            }
        }
    }
    // for(int i=1;i<=n+1;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int sum=0;
    for(int i=1;i<=n+1;i++){
        sum+=dp[n+1][i];
    }
    int base=gcd(sum,dp[n+1][m+1]);
    if(base==0)
        cout << "0/1" << endl;
    else
        cout << dp[n+1][m+1]/base << '/' << sum/base << endl;
    return 0;
}