#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

/**
 * 做一个1e8的筛记录素数个数然后求前缀
 */

int cnt[101010101];
int prime[6550505];
int num;

void solve(){
    int l,r;
    cin >> l >> r;
    cout << cnt[r]-cnt[l-1] << endl;
}

void deal(int lim){
    int j=0;
    for(int i=1;i<=lim;i++){
        if(cnt[i]==2) j++;
        cnt[i]=j;
    }
}

void sieve(int lim){
    for(int i=2;i<=lim;i++){
        if(cnt[i]==0){
            cnt[i]=1;
            prime[++num]=i;
        }
        for(int j=1;j<=num;j++){
            if(i*prime[j]>lim) break;
            cnt[i*prime[j]]=cnt[i]+cnt[prime[j]];
        }
    }
    deal(lim);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    sieve(101010101);
    while(t--){
        solve();
    }
    return 0;
}