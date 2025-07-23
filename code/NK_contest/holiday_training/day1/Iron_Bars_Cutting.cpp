#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
#define ll long long
#define pii pair<ll,ll> 
/**
 * 区间dp
 * 从短的处理到长的
 * 满足max(短区间的不平衡度)小于等于长区间的不平衡度
 * 用一个三位数组all记录(l,r)不同切割点的代价和不平衡度
 * dp[l][r]从l到r最小代价
 * dp[l][r]=min(dp[l][k]+dp[k+1][r]+cost(l,r,k))
 * dp[i][i]=sum-2*min
 */

ll a[450];
vector<pii> all[450][450];
ll dp[450][450];
ll check(int a,int b,ll ib){
    int l=0,r=all[a][b].size()-1;
    while(l<=r){
        int m=(l+r)>>1;
        if(all[a][b][m].first>ib)
            r=m-1;
        else
            l=m+1;
    }
    if(r<0){
        //没找到
        return 2e18;
    }else{
        return all[a][b][r].second;
    }

}
bool cmp(pii a,pii b){ return a.first<b.first; }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;

        a[0]=0;
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                all[i][j].clear();
            }
        }


        for(int i=1;i<=n;i++){
            cin >> a[i];
            a[i]+=a[i-1];
            dp[i][i]=0;
            all[i][i].push_back({0,0});
        }


        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                for(int k=l;k<r;k++){
                    ll llen=a[k]-a[l-1],rlen=a[r]-a[k];
                    ll ib=abs(llen-rlen);
                    ll cost=min(llen,rlen)*(ll)ceil(log2(llen+rlen));
                    cost+=check(l,k,ib);
                    cost+=check(k+1,r,ib);
                    cost=min(cost,(ll)2e18);
                    all[l][r].push_back({ib,cost});
                    dp[l][r]=min(dp[l][r],cost);
                    if(len==n) cout << (cost>=2e18?-1:cost) << ' ';
                }
                // cout << l << ' ' << r << ' ' << dp[l][r] << endl;
                sort(all[l][r].begin(),all[l][r].end(),cmp);

                //代价最小化
                for(int i=1;i<all[l][r].size();i++){
                    all[l][r][i].second=min(all[l][r][i].second,all[l][r][i-1].second);
                }
                if(len==n) cout << endl;
            }
        }
        // cout << dp[1][n] << endl;
    }
    return 0;
}