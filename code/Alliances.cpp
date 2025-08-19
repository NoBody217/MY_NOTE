#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int>G[505050];
vector<int>a[505050];
int dep[505050],lca[505050],dfn[505050];
int b[1010101],fa[505050],vis[505050];
int ba[505050],first[505050];
int f[1010101][20];
// int pre[1010101],sfx[1010101];
int tim,cnt;


void rmq_st(){
    for(int i=1;i<=cnt;i++) f[i][0]=b[i];
    int t=(int)log2(1.0*cnt);
    for(int j=1;j<=t;j++){
        int m=cnt-(1<<j)+1;
        for(int i=1;i<=m;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);        
    }
}

int rmq_find(int l,int r){
    int k=(int)(log2(1.0*(r-l+1)));
    return min(f[l][k],f[r-(1<<k)+1][k]);
}


int gtlca(int l,int r){
    if(first[r]<first[l]) swap(l,r);
    int k=rmq_find(first[l],first[r]);
    return ba[k];
}

void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    dfn[x]=++tim;
    ba[tim]=x;
    b[++cnt]=dfn[x];
    first[x]=cnt;
    for(auto i:G[x]){
        if(i==fa) continue;
        dfs(i,x);
        b[++cnt]=dfn[x];
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1,0);
    rmq_st();

    int k;
    cin >> k;
    for(int i=1;i<=k;i++){
        int cnt;
        cin >> cnt;
        for(int j=0;j<cnt;j++){
            int tmp;
            cin >> tmp;
            fa[tmp]=i;
            if(j==0) lca[i]=tmp;
            else lca[i]=gtlca(lca[i],tmp);
            a[i].push_back(dfn[tmp]);//存dfn用于二分找最小
        }
    }
    for(int i=1;i<=k;i++) sort(a[i].begin(),a[i].end());

    // int p=0;
    // for(int i=1;i<=tim;i++){
    //     if(fa[ba[i]]!=0) p=i;
    //     pre[i]=p;
    // }
    // int s=tim+1;
    // for(int i=tim;i>=1;i--){
    //     if(fa[ba[i]]!=0) s=i;
    //     sfx[i]=s;
    // }

    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int V,t;
        cin >> V >> t;
        int LCA=0;
        vector<int> use;
        for(int j=1;j<=t;j++){
            int tmp;
            cin >> tmp;
            if(j==1) LCA=lca[tmp];
            else LCA=gtlca(LCA,lca[tmp]);
            // vis[tmp]=i;
            use.push_back(tmp);
        }
        int L=gtlca(V,LCA);
        if(L!=LCA){
            cout << dep[LCA]+dep[V]-2*dep[L] << endl;
        }else{
            int ans=INT_MAX;

            for(auto k:use){
                auto p=lower_bound(a[k].begin(),a[k].end(),dfn[V]);
                int pos=p-a[k].begin();
                if(p<a[k].end()){
                    ans=min(ans,dep[V]-dep[gtlca(V,ba[a[k][pos]])]);
                }
                if(p>a[k].begin()){
                    ans=min(ans,dep[V]-dep[gtlca(V,ba[a[k][pos-1]])]);
                }
                

            }

            // int l,r;
            // l=r=dfn[V];
            // while(vis[fa[ba[l]]]!=i&&l!=0) l=pre[l];
            // while(vis[fa[ba[r]]]!=i&&r!=tim+1) r=sfx[r];
            // if(l!=0) ans=min(ans,dep[V]-dep[gtlca(V,ba[l])]);
            // if(r!=tim+1) ans=min(ans,dep[V]-dep[gtlca(V,ba[r])]);


            cout << ans << endl;
        }


    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}