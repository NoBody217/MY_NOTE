#include<bits/stdc++.h>

using namespace std;
/**
 * dp[i][0]=sum(max(dp[u][0],dp[u][1]))
 * dp[i][1]=a[i]+sum(dp[u][0])
 */
int a[10101],dp[10101][2];
vector<int> s[10101];

void dfs(int x){
    dp[x][1]=a[x];
    dp[x][0]=0;
    for(auto i : s[x]){
        dfs(i);
        dp[x][0]+=max(dp[i][0],dp[i][1]);
        dp[x][1]+=dp[i][0];
    }
}

int main(){
    int n;
    cin >> n ;
    int root = n*(n+1)/2;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
    }
    for(int i=1;i<n;i++){
        int l,k;
        cin >> l >> k ;
        root -= l;
        s[k].push_back(l);
    }
    dfs(root);
    int ans = 0 ;
    for(int i=1;i<=n;i++){
        ans = max(dp[i][0],ans);
        ans = max(dp[i][1],ans);
    }
    cout << ans << endl;
    return 0;
}