#include<bits/stdc++.h>

/**
 * gcd(Fn+1,Fn)=gcd(Fn+Fn-1,Fn)=gcd(a,b)
 */


using namespace std;
int main(){
    long long a,b,n;
    cin >> a >> b >> n;
    cout << gcd(a,b) << endl;
    return 0;
}