#include<bits/stdc++.h>
using namespace std;
long long dp[30][30];
int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    n++,m++,x++,y++;
    //为了方便操作，先把整个图往右下挪一点
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            if((abs(x-i)==1&&abs(y-j)==2)||(abs(x-i)==2&&abs(y-j)==1)||(i==x&&j==y)){
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}