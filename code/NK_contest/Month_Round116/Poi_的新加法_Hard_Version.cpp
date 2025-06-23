#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

vector<ull> v(1010101);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t ;
    while(t--){
        int n, q;
        cin >> n >> q ;
        for(int i=0;i<n;i++){
            cin >> v[i] ;
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r ;
            l--;r--;
            if(r-l+1>62){
                cout << 0 << '\n' ;
                continue;
            }
            ull ans=v[l];
            for(int j=l+1;j<=r;j++){
                ans=(ans&v[j])<<1;
            }
            cout << ans << '\n' ;
        }
    }
    return 0;
}