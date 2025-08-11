#include<bits/stdc++.h>
#define pii pair<long long ,long long>
#define int long long
#define endl '\n'
using namespace std;

int n,m;
pii a[101010];
bool cmp(pii x,pii y){
    return abs(x.first-m)>abs(y.first-m);
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i].first;
        a[i].first*=2;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout << a[i].second <<' ';
        // cout << a[i] <<' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}