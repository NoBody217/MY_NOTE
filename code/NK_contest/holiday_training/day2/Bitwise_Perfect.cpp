#include<bits/stdc++.h>
using ll=long long;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n+10);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n>=64) cout << "NO" << endl;
    else{
        int flg=0;//换成for(i,0,n-1&&flg)就不用特判60位，暴力也过
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((a[i]^a[j])<max(a[i],a[j])){
                    flg=1;
                }
            }
        }
        cout << (flg?"NO":"YES") << endl;
    }
    return ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}