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



int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        priority_queue<int,vector<int>,less<int>> q1,q0;
        cin >> n >> a ;
        string s;
        cin >> s;
        int cnt0=0,cnt1=0,cntt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(cnt1!=0){
                    q1.push(cnt1);
                    cnt1=0;
                }
                cnt0++;
            }else{
                cntt++;
                if(cnt0!=0){
                    q0.push(cnt0);
                    cnt0=0;
                }
                cnt1++;                
            }
        }
        q0.push(cnt0);
        q1.push(cnt1);


        // cout << (!q0.empty()?q0.top():-1) <<' ' << (!q1.empty()?q1.top():-1) << endl;


        if((!q0.empty()&&q0.top()>=a+1)||(!q1.empty()&&q1.top()>=a))
            cout << n << endl;
        else
            cout << cntt << endl;
    }    
    return 0;
}
