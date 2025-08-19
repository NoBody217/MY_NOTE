#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[303030];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n; 
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        p[x]=i;
    }
    long long ans = 0;
    int mn=n+1,mx=0;
    for(int i=1;i<=n;i++){
        mn=min(mn,p[i]);
        mx=max(mx,p[i]);
        ans+=mn*(n-mx+1);
    }
    cout << ans << '\n';
    return 0;
}
