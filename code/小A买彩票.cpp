#include<bits/stdc++.h>
using namespace std;
/**
 * dp[i][j]表示买了i张彩票赚j元的可能
 * dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]
 */
long long dp[40][200];
int main(){
    int n;
    cin >> n;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=4*n;j++){
            dp[i][j]=(j>=1?dp[i-1][j-1]:0)+(j>=2?dp[i-1][j-2]:0)+(j>=3?dp[i-1][j-3]:0)+(j>=4?dp[i-1][j-4]:0);
        }
    }
    long long bas=0,sum=0;
    for(int i=0;i<=4*n;i++){
        bas+=dp[n][i];
        if(i>=3*n)sum+=dp[n][i];
    }
    long long deal=gcd(bas,sum);
    if(n==0) cout << "1/1" << endl;
    else if(deal==0) cout << "0/1" << endl;
    else cout << sum/deal << '/' << bas/deal <<endl;
    return 0;
}