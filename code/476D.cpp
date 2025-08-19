#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    cout << (6*n-1)*k << endl;
    for(int i=1;i<=6*n;i+=6){
        cout << k*i << ' ' << k*(i+1) << ' ' << k*(i+2) << ' ' << k*(i+4) << endl;
    }
    return 0;
}