#include<bits/stdc++.h>

using namespace std;

bitset<1010> f[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        f[x][y]=1;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(f[i][j]){
                f[i]|=f[j];
            }
        }
    }
    int ans=n*(n-1)/2;
    for(int i=1;i<=n;i++){
        ans-=f[i].count();
    }
    cout << ans << endl;
    return 0;
}