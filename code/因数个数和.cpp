#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x ;
        long long ans=0;
        for(int j=1;j*j<=x;j++){
            ans+=(x/j-j)*2+1;
        }
        cout << ans << endl;
    }
}