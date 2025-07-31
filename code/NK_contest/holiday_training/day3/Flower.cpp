#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        if(n<=a) cout << "Sayonara" << endl;
        else {
            cout << (n%(a+b)>a||n%(a+b)==0?0:n%(a+b)) <<endl;
        }
    }

    return 0;
}