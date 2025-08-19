#include<bits/stdc++.h>
using namespace std;

//爆搜+剪枝

int a[55];
int n,m,x;
bool dfs(int cnt,int gd,int val){
    if(val+(n-cnt)*gd<x||val>x) return false;
    if(cnt==n){
        if(val==x) return true;
        else return false;
    }
    for(int i=gd;i>=1;i--){
        a[cnt+1]=i;
        if(dfs(cnt+1,gcd(gd,i),val+gcd(gd,i))){
            return true;
        }
    }
    return false;
}

void solve(){
    bool flg=0;
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++){
        a[1]=i;
        if(dfs(1,i,i)){
            flg=1;
            break;
        }
    }
    if(!flg) cout << -1;
    else{
        for(int i=1;i<=n;i++){
            cout << a[i] << ' ';
        }
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
