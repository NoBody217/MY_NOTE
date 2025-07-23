#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using u64=unsigned long long;
constexpr u64 mx = (1<<16)-1;
constexpr u64 MX=ULLONG_MAX;
constexpr int B=16;
const int maxn=1e6+7;

int a[maxn];

int bk[1<<16],pre[1<<16];
u64 sum[1<<16];

void init(){
    for (int i=0; i<(1<<B); i++) {
        for (int j=0;j<16; j++) {
            if((i>>j)&1) {
                break;
            }else{
                pre[i]++;
            }
        }
        for (int j=15;j>=0;j--) {
            if(i >> j & 1) {
                break;
            }else{
                bk[i]++;
            }
        }
        int cur=0;
        for (int j=0;j<16; j++) {
            if (i>>j&1) {
                cur=0;
            }else{
                cur++;
            }
            sum[i]+=cur;
        }
    }  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n,q;
    cin >> n >> q;
    std::vector<u64> a(n);
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        a[i]=s[i]-'0';
    }
    
    const int N=(n+63)/64;
    vector<u64> b(N+20);

    auto get=[&](int x){
        int pos=x/64;
        int res=x%64;
        u64 ans=0;
        ans=(b[pos]>>res)|(b[pos+1]<<(64-res));
        return ans;
    };

    for(int i=0;i<n;i++){
        b[i/64]|=(a[i]<<(i%64));
    }
    
    vector<u64> lobit(65), hibit(65);
    for(int i=0;i<64;i++){
        lobit[i+1]=lobit[i]|(1ull<<i);
        hibit[i+1]=hibit[i]|(1ull<<(63-i));
    }

    vector<int> flip(N+20);
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l,r;
            cin >> l >> r;
            l--;r--;
            int bl=l/64,br=r/64;
            if(bl==br){//同一个块内
                b[bl]^=(lobit[r-l+1]<<(l-bl*64));
            }else{
                b[bl]^=(hibit[64-l%64]);
                b[br]^=(lobit[r%64+1]);
                flip[bl+1]^=1;
                flip[br]^=1;
            }
        }else{
            int l,x,y;
            cin >> l >> x >> y;
            x--,y--;
            //处理之前的翻转
            int v=0;
            for(int i=0;i<N;i++){
                v^=flip[i];
                if(v){
                    b[i]^=MX;
                }
                flip[i]=0;
            }
            //计算结果
            u64 ans=0;
            u64 cur=0;
            int len=l/64;
            int res=l%64;
            for(int i=0;i<len;i++){
                u64 u=get(x)^get(y);
                for(int i=0;i<4;i++){
                    u64 now=u&mx;
                    ans+=sum[now]+1ull*cur*pre[now];
                    if (bk[now] == 16) {
                        cur+=16;
                    } else {
                        cur=bk[now];
                    }
                    u>>=16;
                }
                x+=64,y+=64;
            }
            if(res){
                u64 u=get(x)^get(y);
                for(int i=0;i<res;i++){
                    if(u>>i&1) cur=0;
                    else cur++;
                    ans+=cur;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}