#pragma gcc optimize(3)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct ty{
    int lstb,lstc,num;
};

bool dp[55][55][55*55];
ty pre[55][55][55*55];
bool flg=0;
int n,m,x;
/**
 * dp[i][j][k]第i位前缀gcd为j总权值k
 */


void dfs(int a,int b,int c){
    if(flg) return ;
    if(dp[a][b][c]) return;
    dp[a][b][c]=1;
    if(a>=n){
        if(c==x){
            vector<int> ans(n+10);
            int nb=b,nc=c;
            for(int i=n;i>=1;i--){
                flg=1;
                // cout << i << ' ' << nb << ' ' << nc << endl;
                auto now=pre[i][nb][nc];
                ans[i]=now.num;
                nb=now.lstb;
                nc=now.lstc;
            }
            for(int i=1;i<=n;i++){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        return ;
    }
    for(int i=1;i<=b;i++){
        pre[a+1][gcd(b,i)][c+gcd(b,i)]={b,c,i};
        dfs(a+1,gcd(b,i),c+gcd(b,i));
    }    
}

void solve(){
    flg=0;
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++){
        if(flg) break;
        pre[1][i][i]={0,0,i};
        dfs(1,i,i);
    }
    if(!flg) cout << -1 << endl;
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
