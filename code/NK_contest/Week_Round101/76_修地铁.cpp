#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n/5*2 << ' ';
    cout << (n+5)/10 << ' ';
    cout << n/20*3 << ' '; 
    cout << 2*(n-(n/20)) << endl;
    return 0;
}