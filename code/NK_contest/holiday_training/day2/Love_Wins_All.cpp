#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int p=998244353;

int fa[505050];
long long qpow(long long a,long long b){
    a%=p;
    long long res=1;
    while(b){
      if(b&1) res=res*a%p;
      a=a*a%p;
      b>>=1;
    }
    return res;
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int a,int b){
    fa[find(a)]=find(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){ fa[i]=i; }
        for(int i=1;i<=n;i++){
            int tmp;
            cin >> tmp;
            merge(i,tmp);
        }
        unordered_map<long long,long long> mp;
        for(int i=1;i<=n;i++){
            mp[find(i)]++;
        }
        // cout << ">>" << mp.size() << endl;
        int odd=0,dou=0;
        for(auto [x,y]:mp){
            if(y%2) odd++;
            if(y==2) dou++; 
        }
        // cout << odd << ' ' << dou << endl;
        if(odd!=0&&odd!=2) cout << 0 << endl;
        else if(odd==0){
            //全是偶环，被删的环提供n^2/4，剩下的超过2的环每个提供两种
            long long ans=0;
            for(auto [x,y]:mp){
                ans+=((y*y/4)%p*qpow(2,mp.size()-1-dou+(y==2)))%p;
                ans%=p;
            }
            cout << ans << endl;
        }else {
            //两个奇环删点：奇环每个点可删，删后提供一种方案
            long long ans=1;
            for(auto [x,y]:mp){
                if(y%2)
                    ans=(ans*(y%p))%p;
            }
            ans=(ans*qpow(2,mp.size()-odd-dou))%p;
            cout << ans << endl;
        }
    }
}