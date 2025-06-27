#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
/**
 * dp[i][j]表示倒数第i秒在j位置能获得的最大得分
 */
const int N=1e6+10;
int dp[N][120];
int val[N][120];
int path [N][120];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int W,H;
    cin >> W >> H ;
    int st,x,v,sco;
    int mxt=0;
    while(cin >> st >> x >> v >> sco){
        if((H-1)%v) continue;
        int t=st+(H-1)/v;
        val[t][x]+=sco;
        mxt=max(mxt,t);
    }

    for(int i=mxt;i>=0;i--){
        for(int j=1;j<=W;j++){
            if(j>2&&dp[i+1][j-2]+val[i][j]>dp[i][j]){
                dp[i][j]=dp[i+1][j-2]+val[i][j];
                path[i][j]=-2;
            }            
            if(j>1&&dp[i+1][j-1]+val[i][j]>dp[i][j]){
                dp[i][j]=dp[i+1][j-1]+val[i][j];
                path[i][j]=-1;
            }
            if(dp[i+1][j]+val[i][j]>dp[i][j]){
                dp[i][j]=dp[i+1][j]+val[i][j];
                path[i][j]=0;
            }

            if(j<W&&dp[i+1][j+1]+val[i][j]>dp[i][j]){
                dp[i][j]=dp[i+1][j+1]+val[i][j];
                path[i][j]=1;
            }
            if(j<W-1&&dp[i+1][j+2]+val[i][j]>dp[i][j]){
                dp[i][j]=dp[i+1][j+2]+val[i][j];
                path[i][j]=2;
            }                                    
        }
    }    
    cout << dp[0][(W+1)/2] << endl;
    int depth=0,start=(W+1)/2;
    while(depth<mxt){
        cout << path[depth][start] << endl;
        start+=path[depth][start];
        depth++;
    }
    return 0;
}