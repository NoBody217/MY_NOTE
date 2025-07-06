#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> G[202020];
vector<int> sekai;
vector<int> miku;
pii fa[202020];
int vis[202020];
void bfs(){
    queue<int> q;
    for(int i=0;i<sekai.size();i++){
        q.push(sekai[i]);
        fa[sekai[i]].first=sekai[i];
        fa[sekai[i]].second=0;
        vis[sekai[i]]=1;
    
    }
    while (!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(auto i :G[tmp]){
            if(!vis[i]){
                q.push(i);
                fa[i].first=fa[tmp].first;
                fa[i].second=fa[tmp].second+1;
                vis[i]=1;
            }
        }
    }
}
int cmp(pii a, pii b){
    return a.second>b.second;
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        miku.clear();
        sekai.clear();
        
        int n;
        cin >> n;
        for(int i=0;i<=n;i++) {G[i].clear();fa[i].first=0;fa[i].second=0;}
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b ;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(G[i].size()==1)
                sekai.push_back(i);
        }

        bfs();
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(fa[i].second,mx);
        }
        for(int i=1;i<=n;i++){
            if(fa[i].second==mx) miku.push_back(i);
        }
        cout << miku.size() << endl;
        sort(miku.begin(),miku.end());
        for(int i=0;i<miku.size();i++){
            cout << miku[i] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}