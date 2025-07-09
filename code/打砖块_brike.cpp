#include<bits/stdc++.h>

using namespace std;

const int N=70;
int n,m;

int val[N][N],sum[N][N],dp[N][600][N];

/**
 * 数据读入后形式如下：
 * 1 1 1 1 1
 * 2 2 2 2
 * 3 3 3
 * 4 4
 * 5
 * 敲掉第i列的第j块砖,这一列前面的砖一定已经敲完了
 * 第i-1列最多只能敲j-1块
 * 状态设计：要考虑已经敲了几块，敲到了哪块，当前行敲了几块
 * dp[i][j][k]表示敲到第i列敲了j块当前列敲了k个的最大价值
 * dp[i][j][k]=dp[i-1][j-k][p](p<=k)
 */


int main(){
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cin >> val[i][j];
            sum[i][j]+=sum[i-1][j]+val[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=(n-i+1);k++){
                if(j<k) continue;
                for(int p=0;p<=k+1;p++){
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-k][p]+sum[k][i]);
                }
            }
        }
    }
    cout << max(dp[n][m][1],dp[n][m][0]);
    return 0;
}