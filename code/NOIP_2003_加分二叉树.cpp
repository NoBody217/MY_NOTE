#include<bits/stdc++.h>

using namespace std;


/**
 * dp[i][j]表示区间(i,j)最高分
 * pt[i][j]表示最高分的根
 * dp[i][j]=max(dp[i][j],dp[i][k-1]*dp[k+1][j]+val[k])
 */

int val[40];
long long dp[110][110],pt[110][110];
int n;

void dfs(int l,int r){
    if(l>r) return ;
    if(l==r){
        cout << pt[l][r] << ' ';
        return ;
    }
    //     if(r-l+1==2){
    //         cout << pt[l][r] << ' ' << l+r-pt[l][r] << ' ';
    //         return ;
    //     }
    cout << pt[l][r] << ' ';    
    dfs(l,pt[l][r]-1);
    dfs(pt[l][r]+1,r);
}

int main(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> val[i];
        dp[i][i]=val[i];
        pt[i][i]=i;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                if(dp[i][j]<(k==i?1:dp[i][k-1])*(k==j?1:dp[k+1][j])+val[k]){
                    dp[i][j]=(k==i?1:dp[i][k-1])*(k==j?1:dp[k+1][j])+val[k];
                    pt[i][j]=k;
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << pt[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[1][n] << endl;
    dfs(1,n);
    return 0;
}

