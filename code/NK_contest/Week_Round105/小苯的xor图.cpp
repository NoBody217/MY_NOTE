#pragma gcc optimize(3)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

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

std::mt19937 rng;
int rand(int l,int r){//int随机数生成
    std::uniform_int_distribution<int> distribution(l,r);
    return(distribution(rng));
}

const int p=998244353;

vector<int> G[202020];
int a[202020];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll cnt[2][32]={0};
        for(auto j:G[i]){
            for(int k=0;k<=31;k++){
                if((a[j]>>k)&1) cnt[1][k]++;
                else cnt[0][k]++;
            }
        }
        for(int j=0;j<=31;j++){
            ll tmp=0;
            if((a[i]>>j)&1){
                tmp=((cnt[0][j]*(cnt[0][j]-1))+(cnt[1][j]*(cnt[1][j]-1)))/2;
                ans+=(tmp*(1<<j))%p;
                ans%=p;
            }else{
                tmp=cnt[0][j]*cnt[1][j];
                ans+=(tmp*(1<<j))%p;
                ans%=p;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
