#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    int cnt=0;
    while(n){
        n>>=1;
        cnt++;
    }
    cout << (1ull<<cnt)-1 << endl;
    return 0;
}