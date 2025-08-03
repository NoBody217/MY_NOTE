#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
//题干有问题，应该是至少被占领了一次
vector<int>V;
vector<int>a;
int cnt[201010];
signed main() {
    int n,m;
    cin >> n >> m ;
    a.resize(n+10);
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            V.push_back(i);
            V.push_back(m/i);
        }
    }
    sort(V.begin(),V.end());
    for(int i=0;i<n;i++){
        cin >> a[i];
        int g=__gcd(a[i],m);
        for(int j=0;j<V.size();j++){
            if(V[j]%g==0)cnt[j]=1;
        }
    }
    ll ans=0;
    for(int i=0;i<V.size();i++){
        if(cnt[i]!=0){
            ans+=m*(m/V[i]-1)/2*cnt[i];
            for(int j=i+1;j<V.size();j++){
                if(V[j]%V[i]==0){
                    cnt[j]-=cnt[i];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}