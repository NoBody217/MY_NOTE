#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


/**
 * 背包+二分？
 */

vector<pii> tb;
int dp[202021];

void solve(){
    int n;
    cin >> n;
    cout << dp[n]-1 << endl;
}

int main(){
    memset(dp,0x3f,sizeof(dp));
    int p=202020;
    dp[0]=0;
    for(int i=1;i*(i+1)/2<=p;i++){
        tb.push_back({i*(i+1)/2,i});
    }
    for(int i=0;i<tb.size();i++){
        for(int j=1;j<=202020;j++){
            if(j-tb[i].first<0)continue;
            dp[j]=min(dp[j],dp[j-tb[i].first]+tb[i].second+1);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}