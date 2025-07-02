#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200],b[200],sa,ans;
int main(){
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> a[i] >> b[i];
        if(a[i]<b[i]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}