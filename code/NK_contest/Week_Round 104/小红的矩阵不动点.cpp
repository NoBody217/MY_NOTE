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

std::mt19937 rng;
int rand(int l,int r){//int随机数生成
    std::uniform_int_distribution<int> distribution(l,r);
    return(distribution(rng));
}



int a[505][505];
vector<pair<int,int>> b;
bool mp[505][505];
bool lie[505];
unordered_set<int> f,s;
//250000
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]==min(i,j)){
                ans++;
            }else{
                b.push_back({a[i][j],min(i,j)});
                mp[a[i][j]][min(i,j)]=1;
                lie[min(i,j)]=1;
            }
        }
    }
    int flg=0;
    for(auto p:b){
        if(mp[p.second][p.first]){
            cout << ans+2 << endl;
            return 0;
        }
        if(lie[p.first]){
            flg=1;
        }
    }
    cout << (ans+flg) << endl;
    return 0;
}
