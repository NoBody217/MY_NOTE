#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct ty{
    int x,y,l,h;
}edge[1010110];
vector<int> bian[1010110];
int h[1010110],fa[1010110];
int vis[101010];
long long num,ans;
int n,m;

bool cmp(ty a,ty b){
    if(a.h==b.h) return a.l<b.l;
    else return a.h>b.h;
}

void dfs(int x){
    num++;
    vis[x]=1;
    for(auto i:bian[x]){
        if(vis[i])continue;
        dfs(i);
    }
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=m;i++){
        int a,b,k;
        cin >> a >> b >> k;
        if(h[a]>=h[b]) bian[a].push_back(b);
        if(h[b]>=h[a]) bian[b].push_back(a);
        edge[i].x=a;
        edge[i].y=b;
        edge[i].l=k;
        edge[i].h=min(h[a],h[b]);
    }
    dfs(1);
    sort(edge+1,edge+m+1,cmp);
    // for(int i=1;i<=m;i++) cout << edge[i].x << ' ' << edge[i].y << endl;
    // for(int i=1;i<=n;i++) cout << vis[i] << ' ';
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int tx=edge[i].x;
        int ty=edge[i].y;
        int fx=find(tx);
        int fy=find(ty);
        if(!vis[ty]||!vis[tx]||fx==fy) continue;
        ans+=edge[i].l;
        fa[fx]=fy;
    }
    cout << num << ' ' << ans << endl;
}