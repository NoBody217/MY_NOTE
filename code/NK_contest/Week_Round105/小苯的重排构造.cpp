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



int a[202020];
int main(){
    int n,k;
    cin >> n >> k;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==1) cnt1++;
        else cnt2++;
    }
    // cout << cnt1 << ' ' << cnt2 << endl;
    if(k>cnt1+(cnt2-1)*2){
        cout << -1 << endl;
        return 0;
    }
    else if(k<cnt1&&cnt1>=cnt2-1){
        cout << -1 << endl;
        return 0;
    }
    else if(k<cnt1+2*(cnt2-cnt1-1)&&cnt1<cnt2-1){
        cout << -1 << endl; 
        return 0;
    }else{
        int mxans=cnt1+2*(cnt2-1);
        int need=mxans-k;
        for(int i=1;i<=need;i++){
            cout << "2 1 " ;
            cnt1--;
            cnt2--;
        }
        for(int i=1;i<=cnt2;i++){
            cout << "2 ";
        }
        for(int i=1;i<=cnt1;i++){
            cout << "1 ";
        }
        cout << endl;

    }
    
    return 0;
}
