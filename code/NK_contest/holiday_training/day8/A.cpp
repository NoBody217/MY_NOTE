#include<bits/stdc++.h>
using namespace std;


void solve(){
    string x;
    cin >> x;
    if(x=="0") cout << 10 << endl;
    else if(x=="-0") cout << -10 << endl;
    else if(x[0]!='-'){
        bool flg=1;
        for(int i=0;i<x.size();i++){
            if(x[i]=='0'&&flg==1){
                cout << '1';
                flg=0;
            }
            cout << x[i];
        }
        if(flg) cout << '1';
        cout << endl;
    }else{
        bool flg=1;
        cout << '-';
        for(int i=1;i<x.size();i++){
            if(x[i]>'1'&&flg==1){
                cout << '1';
                flg=0;
            }
            cout << x[i];
        }
        if(flg) cout << '1';
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}