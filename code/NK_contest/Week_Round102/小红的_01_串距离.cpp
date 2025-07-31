#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    int flg[3];
    int cnt=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            flg[cnt++]=i;
        }
    }
    cout << ((flg[1]-flg[0]==flg[2]-flg[1])?"Yes":"No") << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}