#include<iostream>
using namespace std;
using ll=long long ;
const int N=13e6+10;
const int p=1e9+7;


ll qpow(ll a,ll b){
    a%=p;
    ll res=1;
    while(b){
      if(b&1) res=res*a%p;
      a=a*a%p;
      b>>=1;
    }
    return res;
}

int prime[N];
bool v[N];
ll res[N];

int ans=1;
int cnt=0;

int main(){
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            prime[cnt++]=i;
            v[i]=1;
            res[i]=qpow(i,n);
        }
        for(int j=0;j<cnt;j++){
            if(prime[j]*i>n) break;
            v[i*prime[j]]=1;
            res[i*prime[j]]=res[i]*res[prime[j]]%p;
        }
        ans^=res[i];
    }
    cout << ans << endl;
    return 0;
}