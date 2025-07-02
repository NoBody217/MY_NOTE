#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

/**
 * dp[i][j][k]表示第i行状态j，i-1行状态为k
 * dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][p]+num[j])
 * H=1,P=0;
 */

int N,M;
int mp[120],dp[120][100][100];
vector<int>st;
vector<int>num;

int calc(int x){
    int ans=0;
    while(x){
        ans+=x&1;
        x>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);    
    cin >> N >> M;
    //build the map
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            char c;
            cin >> c;
            if(c=='H') mp[i]|=(1<<(j-1));
        }
    }
    
    //find all condition
    for(int i=0;i<(1<<M)-1;i++){
        if(i&(i<<1)||i&(i<<2)) continue;
        st.push_back(i);
        num.push_back(calc(i));
    }

    //dp
    for(int i=1;i<=N;i++){
        for(int j=0;j<st.size();j++){
            if(st[j]&mp[i])continue;
            for(int k=0;k<st.size();k++){
                if(st[j]&st[k])continue;
                for(int p=0;p<st.size();p++){
                    if(st[p]&st[k]||st[p]&st[j]) continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][p]+num[j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<st.size();i++){
        for(int j=0;j<st.size();j++){
            ans=max(ans,dp[N][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}