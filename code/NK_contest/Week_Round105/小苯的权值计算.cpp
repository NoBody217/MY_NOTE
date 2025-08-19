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

std::mt19937 rng;
int rand(int l,int r){//int随机数生成
    std::uniform_int_distribution<int> distribution(l,r);
    return(distribution(rng));
}



int a[30];
int b[30];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        b[i]=a[i]^a[i+1];
    }
    int ans=b[0];
    for(int i=1;i<n-1;i++){
        ans=gcd(ans,b[i]);
    }
    cout << ans << endl;
    return 0;
}
