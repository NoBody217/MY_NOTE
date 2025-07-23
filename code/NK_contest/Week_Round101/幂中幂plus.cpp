#include<bits/stdc++.h>

using namespace std;

using ll=long long;

ll bas,c0,p;
int vis[1010110];
ll a[1010110];

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


int main(){
    cin >> bas >> c0 >> p;
    ll pre=c0,head=0,T=0,T_val;
    int cnt=1;
    while(true){
        ll nxt=qpow(bas,pre);
        // cout << pre << ' ' << nxt << endl;
        if(vis[nxt]){
            head=vis[nxt]-1;
            T=vis[pre]-vis[nxt]+1;
            T_val=(a[cnt-1]-a[head]+p)%p;
            break;
        }else{
            vis[nxt]=cnt;
            a[cnt]=(nxt+a[cnt-1])%p;
            cnt++;
        }
        pre=nxt;
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        ll k;
        cin >> k;
        if(k<cnt) cout << a[k]%p << endl;
        else{
            ll ans=0;
            k-=head;
            ans+=a[head];
            ans+=((k/T)%p)*(T_val%p);
            ans%=p;
            ll res=k%T;
            ans+=(a[head+res]-a[head]+p)%p;
            ans%=p;
            cout << ans << endl;
        }
    }
}