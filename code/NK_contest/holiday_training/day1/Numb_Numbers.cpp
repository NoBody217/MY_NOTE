#include<bits/stdc++.h>

using namespace std;
using ll=long long;
ll a[202020];
int main (){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        map<ll,ll> mp;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            mp[a[i]]++;
        }
        int mid=n-n/2;
        auto it=mp.begin();
        ll cnt=0;
        for(int i=0;i<q;i++){
            int id,v;
            scanf("%d%d",&id,&v);
            id--;
            ll pre=a[id];
            mp[a[id]]--;
            a[id]+=v;
            mp[a[id]]++;
            if(pre<it->first&&a[id]>=it->first){
                cnt--;
            }
            while(cnt+it->second<=mid){
                cnt+=it->second;
                it++;
            }
            printf("%lld\n",cnt);
        }

    }
    return 0;
}