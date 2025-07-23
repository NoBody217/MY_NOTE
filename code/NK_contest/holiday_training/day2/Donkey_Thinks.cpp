#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
/**
 * 总价值=sum(h_i)-(V-sum(s_i))*sum(d_i)
 * 可以视作一个装满V-U的体积，每个物品价值为(h_i-U*d_i)的01背包
 * 枚举U
 * 
 */

ll h[101010],s[101010],d[101010];
vector<ll> chip[600];
ll dp[600];
void solve(){
    ll ans=0;
    int n,V;
    cin >> n >> V;
    for(int i=1;i<=n;i++){
        cin >> h[i] >> s[i] >> d[i];
    }
    for(int v_now=1;v_now<=V;v_now++){//枚举当前体积
        int u=V-v_now;
        for(int i=0;i<=v_now;i++){
            chip[i].clear();
            dp[i]=-1e18;
        }
        for(int i=1;i<=n;i++){//计算当前体积下的价值
            chip[s[i]].push_back(h[i]-u*d[i]);
        }
        dp[0]=0;
        for(int i=1;i<=v_now;i++){//枚举每个体积的物品
            //算每个体积的物品能取多少件
            int cnt=min(v_now/i,(int)chip[i].size());
            nth_element(chip[i].begin(),chip[i].begin()+cnt-1,chip[i].end(),greater<ll>());
            for(int j=0;j<cnt;j++){
                for(int k=v_now;k>=i;k--){
                    dp[k]=max(dp[k],dp[k-i]+chip[i][j]);
                }
            }
        }
        ans=max(ans,dp[v_now]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }    
}