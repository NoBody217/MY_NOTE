#include<bits/stdc++.h>

using namespace std;


/**
 * 对已知根情况下求总深度直接dfs就可以
 * 如果把原有根a和子树根b互换，b上的所有点深度-1，其它点深度+1
 * sum[b]=sum[a]-cnt[b]+(n-cnt[b])
 * 一遍dfs求任意一个根，一个dfs换根即可
 */

vector<int> G[1010101];
int dep[1010101],cnt[1010101];
long long f[1010101];
int n;
void dfs1(int x,int fa){
    cnt[x]=1;
    for(auto i:G[x]){
        if(i==fa) continue;
        dep[i]=dep[x]+1;
        dfs1(i,x);
        cnt[x]+=cnt[i];
    }
}

void dfs2(int x,int fa){
    for(auto i:G[x]){
        if(i==fa) continue;
        f[i]=f[x]-cnt[i]+(n-cnt[i]);
        dfs2(i,x);
    }
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++){
        f[1]+=dep[i];
    }
    dfs2(1,0);
    long long ans=f[1];
    for(int i=2;i<=n;i++){
        ans=min(ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}