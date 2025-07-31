#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int v[40404],prime[40404],pi[40404];
int cnt=0;
ll ans=0;
void sieve(int x){
    for(int i=2;i<x;i++){
        if(v[i]==0){
            v[i]=i;
            pi[i]=i-1;
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(prime[j]>v[i]) break;
            if(i*prime[j]>x) break;
            v[i*prime[j]]=prime[j];
            if(v[i]==prime[j]) pi[i*prime[j]]=prime[j]*pi[i];
            else pi[i*prime[j]]=pi[i]*pi[prime[j]];
        }
        ans+=pi[i];
        // cout << i << ' ' << pi[i] <<' '<< v[i]<< endl;
    }
}


int main(){
    int n;
    cin >> n ;
    sieve(n);
    cout << ans*2+3 << endl;
    return 0;
}