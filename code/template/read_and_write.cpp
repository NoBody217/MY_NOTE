#include<bits/stdc++.h>
using namespace std;

//快读
int read(){
    int x=0;f=1;
    char c=getchar;
    while(c<'0||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c<'0||c>'9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
//快写
void write(int x){
    if(x<0) putchar('_'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
//__int128
__int128 read(){
    __int128 res=0;
    string s;
    cin >> s ;
    for(int i=0;i<s.size();i++){
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}
__int128 print(__int128 num){
    if(num>9) print(num/10);
    putchar(num%10+'0');
}

int main(){
    
    return 0;
}
