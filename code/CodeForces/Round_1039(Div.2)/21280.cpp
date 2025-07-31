#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,c;
    cin >> n >> c;
    int a[40];
    priority_queue<int,vector<int>,less<int>> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        q.push(a[i]);
    }
    int t=0;
    int ans=0;
    while(!q.empty()){
        while(!q.empty()&&q.top()*pow(2,t)>c){
            // cout <<">>" << q.top() << ' ' << t <<endl;
            q.pop();
            ans++;
        }
        if(!q.empty()) q.pop();
        t++;
    }
    cout << ans << endl;
}


int main(){
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}