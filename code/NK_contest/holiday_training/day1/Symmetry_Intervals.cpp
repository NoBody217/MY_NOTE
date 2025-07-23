#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;
    
    for(int i=0;i<q;i++){
        string t;
        cin >> t;
        t+=' ';
        int a;
        cin >> a;
        int tmp=0,ans=0;
        for(int j=0;j<t.size();j++){
            if(t[j]==s[j+a-1]&&j+a-1<s.size()){
                tmp++;
            }else{
                // cout << j << ' ' << tmp << endl;
                ans+=tmp*(tmp+1)/2;
                tmp=0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}