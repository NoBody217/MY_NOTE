#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int p=1e9+7;

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;   
    cout << qpow(2,n-1) << endl;
}