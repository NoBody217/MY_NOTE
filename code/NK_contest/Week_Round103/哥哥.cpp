#include<bits/stdc++.h>

using namespace std;

const int p=1e9+7;
int cnt0[1010110],cnt1[1010110];

void solve(){
    int n;
    cin >> n ;
    string s;
    cin >> s;
    s=' '+s;
    int cnt=0;
    for(int i=2;i<=n;i++){
        if((s[i]=='1'&&s[i-1]=='0')||s[i]=='0'&&s[i-1]=='1')
            cnt++;
    }
    if(cnt>=3) cout << 0 << endl;
    else if(cnt==0) cout << 2 << endl;
    else {
        for(int i=1;i<=n;i++){
            int cur=cnt;
            if(i>=2){
                if(s[i]==s[i-1]) cur++;
                else cur--;           
            }
            if(i<n){
                if(i<=n&&s[i]==s[i+1]) cur++;
                else cur--;
            }

            if(cur>=3){
                cout << 1 << endl;
                return ;
            }
        }
        cout << 2 << endl;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

