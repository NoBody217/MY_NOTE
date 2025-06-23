#include<bits/stdc++.h>
using namespace std;

int a[200],b[200],vis[20202];
int dp[20202];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int L,S,T,M;
    memset(dp,0x3f3f3f3f,sizeof(dp));

    cin >> L >> S >> T >> M ;
    if(S==T){
        int ans=0;
        for(int i=1;i<=M;i++){
            cin >> a[i] ;
            if(a[i]%S==0) ans++;
        }
        cout << ans << '\n';
        return 0;
    }
    for(int i=1;i<=M;i++){
        cin >> a[i] ;
    }
    sort(a+1,a+1+M);

    //路径压缩
    for(int i=1;i<=M;i++){
        if(a[i]-a[i-1]>72){
            b[i]=b[i-1]+72;
        }else{
            b[i]=b[i-1]+(a[i]-a[i-1]);
        }
    }
    
    for(int i=1;i<=M;i++) vis[b[i]]=1;
    // for(int i=1;i<=M;i++) cout << b[i] << ' ' ;
    
    b[M+1]=b[M]+1;
    dp[0]=0;
    // cout << b[M+1] << '\n';
    for(int i=1;i<=b[M+1];i++){
        for(int j=S;j<=T;j++){
            if(i<j) continue;
            // cout << i << ' ' << j << '\n';
            dp[i]=min(dp[i],dp[i-j]+vis[i]);
        }
    }
    cout << dp[b[M+1]] << '\n' ;
    return 0;
    
}