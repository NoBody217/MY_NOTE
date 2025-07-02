#include<bits/stdc++.h>

using namespace std;
int vis[256];
int main(){
    string s,t;
    cin >> s >> t;
    
    for(int i=0;i<=t.size();i++){
        vis[t[i]-'A']=1;
    }

    for(int i=1;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'&&vis[s[i-1]-'A']==0){
            cout << "No" ;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}