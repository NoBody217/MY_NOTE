#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        long long tp=abs(a*a-b*b);
        cout << max(1ll,tp-(tp/2-tp/4+2)) << endl;
    }
    return 0;
}