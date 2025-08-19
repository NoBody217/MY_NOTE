#include<bits/stdc++.h>

using namespace std;

const int lim=200;
int dp[450][2];

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n+10,0);
        int mn=200,mx=-1;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            mn=min(a[i],mn);
            mx=max(a[i],mx);
        }
        if(m==2){
            int ans=0x3f3f3f3f;
            for(int u=mn;u<=lim;u++){
                for(int v=u;v<=lim;v++){
                    memset(dp,0x3f,sizeof(dp));
                    dp[1][0]=(u-a[1]>=0?u-a[1]:0x3f3f3f3f);
                    dp[1][1]=(v-a[1]>=0?v-a[1]:0x3f3f3f3f);
                    for(int i=2;i<=n;i++){
                        if(a[i]<=u){
                            dp[i][0]=min(dp[i-1][0]+max(0,(u-a[i])-(u-a[i-1])),dp[i-1][1]+max(0,(u-a[i])-(v-a[i-1])));
                        }
                        if(a[i]<=v){
                            dp[i][1]=min(dp[i-1][0]+max(0,(v-a[i])-(u-a[i-1])),dp[i-1][1]+max(0,(v-a[i])-(v-a[i-1])));
                        }
                    }
                    
                    ans=min(ans,min(dp[n][0],dp[n][1]));
                    // cout << u << ' ' << v << ' ' << dp[n][0] << ' ' << dp[n][1] << ' ' << ans << endl;
                }
            }
            cout << ans << endl;            
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                a[i]=mx-a[i];
            }
            for(int i=1;i<=n;i++){
                ans+=max(0,a[i]-a[i-1]);
            }
            cout << ans << endl;
        }

    }
    return 0;
}