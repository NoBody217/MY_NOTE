#include<bits/stdc++.h>
using namespace std;

const int p=1e9+7;

/**
 * 加法原理和乘法原理
 * 如果没有限制，每个位置可以选择1~n，m个位置
 * 总价值为(n*(n+1)/2)^m
 * 然后对于没限制的部分就按照公式算
 * 有限制的部分单独算
 * 快速幂传参记得一致
 */
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
long long ans=0;
set<int> st[101010];
map<int,int> mp;
int cnt;
int main(){
    long long n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        if(mp.find(x)==mp.end()){
            mp[x]=cnt++;
        }
        st[mp[x]].insert(y);
    }
    ans=qpow(n*(n+1)%p/2,m-cnt);
    for(int i=0;i<cnt;i++){
        long long cur=n*(n+1)%p/2;
        for(auto j:st[i]){
            cur=(cur-j+p)%p;
        }
        ans=ans*cur%p;
    }
    cout << ans << endl;

    return 0;
}