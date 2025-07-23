#include<bits/stdc++.h>

#define pii pair<int,int>
using namespace std;
const int N = 6*202020;

vector<pii>e[N];
bool vis[N];
int fa[N];
int val[N];
pii oud[N];

int main(){
    int n;
    cin >> n;
    int tot=0;
    for(int i=1;i<=n;i++){
        int ct;
        cin >> ct;
        tot+=ct;
        e[i].resize(ct);
        for(int j=0;j<ct;j++){
            cin >> e[i][j].first;
            e[i][j].second=0;
        }
    }
    int idx=0;
    tot/=2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<e[i].size();j++){
            if(e[i][j].second) continue;
            e[i][j].second=++idx;
            int to=e[i][j].first;

            for(int k=0;k<e[to].size();k++){
                if(e[to][k].first==i){
                    e[to][k].second=tot+idx;
                    oud[idx].first=to,oud[idx].second=k;
                    oud[idx+tot].first=i,oud[idx+tot].second=j;
                }
            }
        }
    }
    int cyn=0;
    for(int i=1;i<=tot*2;i++){
        if(fa[i]) continue;
        cyn++;
        vector<int> path;
        for(int j=i;!fa[j];){
            fa[j]=cyn;
            path.push_back(j);
            int nxt=e[oud[j].first][(oud[j].second+1)%e[oud[j].first].size()].second;
            j=nxt;
        }
        int ans=0;
        for(auto j:path){
            if(!vis[j%tot]){
                vis[j%tot]=1;
                ans++;
            }
        }
        for(auto j:path){
            vis[j%tot]=0;
        }
        val[cyn]=ans;
    }
    for(int i=1;i<=n;i++){
        int id=e[i][0].second;
        cout << val[fa[id]] << endl;
    }
}