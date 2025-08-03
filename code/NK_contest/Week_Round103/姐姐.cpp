#include<bits/stdc++.h>

using namespace std;


int a[202020];
void solve(){ 
    int cnt=0;
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==1&&a[i-1]==0&&i>=2) cnt++;
    }
    if(a[n]==0&&a[1]==1)cnt++;
    cout << (cnt<=1?"YES":"NO") << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}