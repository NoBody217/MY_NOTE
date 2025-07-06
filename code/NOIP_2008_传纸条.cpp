#include<bits/stdc++.h>

using namespace std;

/**
 * dp[i][j][k][l]第一个人在(i,j)第二个在(k,l)和最大
 * dp[i][j][k][l]=dp四个方向
 */
int dp[60][60][60][60];
int a[60][60];
int n,m;

int judge(int i,int j,int k,int l){
    if(i==1&&j==1&&k==1&&l==1)return 0;
    if(i==m&&j==n&&k==m&&l==n)return 0;
    return 1;
}
int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                for(int l=1;l<=n;l++){
                    if(i==k&&j==l&&judge(i,j,k,l)) dp[i][j][k][l]=-0x3f3f3f3f;
                    else dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])))+a[i][j]+a[k][l];

                }
            }
        }
    }
    cout << dp[m][n][m][n] <<endl;
    return 0;
}