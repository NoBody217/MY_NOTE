#include<bits/stdc++.h>
using namespace std;
long long n;

void solve(){
    cout << n-(n/2+n/5+n/11+n/13
    -n/(2*5)-n/(2*11)-n/(2*13)-n/(5*11)-n/(5*13)-n/(11*13)
    +n/(2*5*11)+n/(2*5*13)+n/(2*11*13)+n/(5*11*13)
    -n/(2*5*11*13)) <<endl;
}
int main(){
    while(cin >> n){
        solve();
    }
}