#include<bits/stdc++.h>
#define int long long
using namespace std;

int c[202020],flg[1010];
int n,m;

int lowbit(int x){ return x&(-x); }
void add (int x,int val){
    while(x<=n){
        c[x]+=val;
        x+=lowbit(x);
    }
}
int cal(int x){
    int sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

signed main(){
    cin >> n >> m ;
    while(lowbit(n)!=n) n+=lowbit(n);

    for(int i=1;i<=m;i++){
        int op,x,y;
        cin >> op >> x >> y;
        if(op==1){
            if(x*x<=n){
                flg[x]+=y;
            }else{
                for(int j=x;j<=n;j+=x){
                    add(j,y);
                }
            }
        }else{
            int ans=cal(y)-cal(x-1);
            for(int j=1;j*j<=n;j++){
                ans+=((y/j)-((x-1)/j))*flg[j];
            }
            cout << ans << endl;
        }
    }
}