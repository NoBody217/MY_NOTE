#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


/**
 * 背包+二分？
 */

vector<pii> tb;
int dp[202021];
vector<int> path(202021);
int pre;
void solve(){
    int n;
    cin >> n;
    while(n>0){
        int len=path[n];
        n-=len*(len+1)/2;
        cout << string(len,'1');
        if(n!=0)cout << '0';
    }
    cout << endl;

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
            if(dp[j-tb[i].first]+tb[i].second+1<dp[j]){
                dp[j]=dp[j-tb[i].first]+tb[i].second+1;
                path[j]=tb[i].second;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}