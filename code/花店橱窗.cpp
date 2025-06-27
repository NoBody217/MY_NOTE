#include<bits/stdc++.h>

using namespace std;
/**
 * 所有的花束在放入花瓶时必须保持其标识数的顺序，即：
 * 杜鹃花必须放在秋海棠左边的花瓶中
 * 秋海棠必须放在康乃馨左边的花瓶中
 * dp[i][j]表示前i朵花，用前j个盆且第i朵花放到第j个盆里最大价值
 * dp[i][j]=dp[i-1][1~j-1]+a[i][j]
 * 初始化：没放的时候每个位置都应该是极小值，第0行应该是0,便于转移，每个花盆放在最小位置需要手动初始化
 */
long long dp[120][120];
long long val[120][120];
int path[120][120];

void printpath(int n,int dep){
    if(dep==0) return;
    printpath(path[dep][n],dep-1);
    cout << n << ' ' ;
}
int main(){
    int f,v;
    cin >> f >> v;

    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            cin >> val[i][j];
        }
    }


    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            dp[i][j]=-0x3f3f3f3f;
            if(i==j){
                dp[i][j]=dp[i-1][j-1]+val[i][j];
                path[i][j]=i-1;
            }            
        }        
    }

    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            for(int k=1;k<j;k++){
                if(dp[i][j]<dp[i-1][k]+val[i][j]){
                    dp[i][j]=dp[i-1][k]+val[i][j];
                    path[i][j]=k;
                }
            }
        }
    }



    long long ans=-0x3f3f3f3f;
    int idx=-1;
    for(int i=f;i<=v;i++){
        if(dp[f][i]>ans){
            ans=dp[f][i];
            idx=i;
        }
    }
    cout << ans << endl ;
    printpath(idx,f);
    return 0;

}