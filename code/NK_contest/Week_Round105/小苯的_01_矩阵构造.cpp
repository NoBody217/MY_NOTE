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



int maze[1010][1010];
int main(){
    int n,k;
    cin >> n >> k;
    if(k%2){
        cout << -1 << endl;
        return 0;
    } 
    int cnt=k/2;
    for(int i=1;i<=cnt;i++){
        maze[i][i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
