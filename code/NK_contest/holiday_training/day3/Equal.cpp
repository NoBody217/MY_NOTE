#pragma gcc optimize(3)
#include<bits/stdc++.h>
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
 * n=1 Yes
 * n=2 除非相等
 * n>=3
 * 对于每一个质因子p考虑
 * a_i中p的次数记为b_i
 * 
 * n%2==0 sum(b_i)%2==1 如果相同，则所有b_i相等，则n*b_i一定是偶数，与sum奇偶性不同，无解
 * n%2==0 sum(b_i)%2==0 对于给定的操作，每次可以使sum-=2||sum+=2,最终使sum变为0
 * n%2==1 sum(b_i)%2==1 先通过若干次+2使得每个b_i>=1，记c_i=b_i-1，则sum(c_i)=sum(b_i)-n，最终sum(c_i)是一个偶数，可以将sum(c_i)变为0，那么所有b_i==1
 * n%2==1 sum(b_i)%2==0 无所谓，只要sum(b_i)是偶数，就可以变为全0
 * 综上n为奇数直接YES，n为偶数，判断每一个质因子出现的次数和，如果和是偶数就YES，奇数就NO
 * 先做一遍筛法，得知每个数的最小质因子
 * 然后开一个cnt，记录每个质因子出现的次数
 * cnt[v[a_i]]++;a_i/=v[a[i]];直到a_i==i
 * 这样复杂度是O(Nlog(max(a_i)))
 * 最终看cnt奇偶不用遍历，开一个变量cnt_odd，当一个数从偶数变成奇数就给cnt_odd++，否则就cnt_odd--，最终检查是不是0即可
 * 另一个方法，把所有质数映射到随机值，然后同上面记录cnt的方法，把a_i映射成所有质因子的异或和f_i，最终把f_i求一个异或和，如果是0就是偶数次
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
        for(int i=0;i<n;i++){
            while(a[i]!=1){
                f[i]^=h[v[a[i]]];
                a[i]/=v[a[i]];
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum^=f[i];
        }
        cout << (sum==0?"YES":"NO") << endl;
    }
}


int main(){
    int T;
    cin >> T;
    seive(5000010);
    // cout << cnt <<endl; //348513个
    while(T--){
        solve();
    }
    return 0;
}
