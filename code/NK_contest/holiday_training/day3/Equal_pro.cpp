#pragma gcc optimize(3)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//快读
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c<'0'||c>'9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
//快写
void print(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
//__int128
__int128 read128(){
    __int128 res=0;
    string s;
    cin >> s ;
    for(int i=0;i<s.size();i++){
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}
void print128(__int128 num){
    if(num>9) print128(num/10);
    putchar(num%10+'0');
}

std::mt19937_64 rng;
long long rand(long long l,long long r){//long long随机数生成
    std::uniform_int_distribution<long long> distribution(l,r);
    return(distribution(rng));
}

/**
 * 换一种写异或哈希的方法
 */


int prime[1010110],v[5010101];
long long h[5010101];
int cnt=0;
void seive(int x){
    for(int i=2;i<=x;i++){
        if(v[i]==0){
            prime[++cnt]=i;
            v[i]=i;
            h[i]=rand(1ll,(1ll<<62));
        }
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>x||prime[j]>v[i])break;
            v[i*prime[j]]=prime[j];
            h[i*prime[j]]=h[i]^h[prime[j]];
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+10);
    vector<long long> f(n+10);
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    if(n%2) cout << "YES" << endl;
    else if(n==2) cout << (a[0]==a[1]?"YES":"NO") << endl;
    else{
        long long sum=0;
        for(int i=0;i<n;i++){
            sum^=h[a[i]];
        }
        cout << (sum==0?"YES":"NO") << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    seive(5000010);
    // cout << cnt <<endl; //348513个
    while(T--){
        solve();
    }
    return 0;
}
