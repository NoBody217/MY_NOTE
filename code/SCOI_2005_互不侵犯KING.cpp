#include<bits/stdc++.h>
using namespace std;

/**
 * dp[i][j][k]表示第i行状态为k总共摆j个的方案数
 * dp[i][j][k]=dp[i-1][j-num[k]][p]
 */

int calc(int x){
    int ans=0;
    while(x){
        if(x&1)ans++;
        x>>=1;
    }
    return ans;
}
long long dp[10][120][120];
vector<int> st;
vector<int> num;
int main(){
    int n,k;
    cin >> n >> k;
    //枚举可能的状态
    for(int i=0;i<(1<<n);i++){
        if(i&(i<<1))continue;
        st.push_back(i);
        num.push_back(calc(i));
    }

    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int cur=0;cur<st.size();cur++){
                if(num[cur]>j) continue;
                for(int lst=0;lst<st.size();lst++){
                    if(num[lst]+num[cur]>j) continue;
                    if((st[cur]&st[lst])||(st[cur]&(st[lst]<<1))||(st[cur]&(st[lst]>>1))) continue;
                    dp[i][j][cur]+=dp[i-1][j-num[cur]][lst];
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<st.size();i++){
        ans+=dp[n][k][i];
    }
    cout << ans << endl;
    return 0;
}