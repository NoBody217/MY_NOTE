#include<bits/stdc++.h>
#define int long long

using namespace std;

int a[202020],dp[202020];
int res=-0x3f3f3f3f;
vector<int> t[202020];

void dfs(int x,int fa){
    dp[x]=a[x];
    res=max(res,dp[x]);
    for(auto i:t[x]){
        if(i==fa) continue;
        dfs(i,x);
        res=max(res,dp[x]+dp[i]);
        dp[x]=max(dp[x],dp[i]+a[x]);
    }
}
signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y ;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfs(1,0);
    cout << res << endl;

    return 0;
}