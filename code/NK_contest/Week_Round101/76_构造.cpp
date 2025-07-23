#include<bits/stdc++.h>

using namespace std;

int gt(int x){
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans;
}
int vis[102020];
int ans[102020];
int main(){
    int n,m;
    cin >> n >> m;
    int szn=gt(n),szm=gt(m);
    // cout << szn << ' ' << szm << endl;
    if(szn<szm||m%2==0) cout << -1 << endl;
    else{
        int cnt=0;
        for(int i=szm-1;i>0;i--){
            if((m>>i)&1){
                ans[++cnt]=(1<<i);
                vis[1<<i]=1;
            }
        }
        
        int cnt2=cnt;
        for(int i=1;i<=n;i++){
            if(vis[i]==0) ans[++cnt2]=i;
        }

        for(int i=1;i<=n;i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
        cout << cnt+1 << endl;
        for(int i=1;i<=cnt;i++){
            cout << i << ' ' << i << endl;
        }
        cout << cnt+1 << ' ' << n << endl;
    }
    return 0;
}