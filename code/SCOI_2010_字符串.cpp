#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=20100403;

int f[2010101];
void cal(int x){
    f[1]=1;
    for(int i=2;i<=x;i++){
        f[i]=i*f[i-1]%p;
    }
}
int C(int x,int y){
    int up=p-2;
    int res=1;
    int bas=f[y]*f[x-y]%p;
    while(up){
        if(up&1){
            res=res*bas%p;
        }
        bas=bas*bas%p;
        up>>=1;
    }
    return (f[x]*res%p);
}
signed main(){
    int n,m;
    cin >> n >> m;
    if(n<m) cout << 0 << endl;
    else{
        cal(n+m);
        cout << ((C(n+m,m)-C(n+m,n+1)+p)%p) << endl;
    }
    return 0;
}