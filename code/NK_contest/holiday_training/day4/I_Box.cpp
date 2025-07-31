#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
/**
 * 每个箱子广搜
 * 途中遇到未到位的箱子怎么办？
 * 途中遇到已经到位的箱子怎么办？
 * 每个箱子搜出来一条路，回溯这个路，回溯的过程中，如果遇到已经占位的别的箱子，就分成两段
 * Eg.A->C中间，B处有一个箱子，所得路径C->a
 * 从C回溯，到B遇见障碍，将C->B记为一段
 * 然后从B继续回溯，直到A
 * 这样就获得了B->C，A->B的两段路径
 */

int n,m;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
string mp[55];
vector<pair<pii,pii>> path;
int vis[55][55];
int prex[55][55];
int prey[55][55];
vector<pair<pair<int,int>,char>> ans;

char getdir(pii now,pii lst){
    if(now.f==lst.f){
        return lst.s>now.s?'L':'R';
    }else{
        return lst.f>now.f?'U':'D';
    }
}

void creat(){
    // for(auto [x,y]:path){
    //     cout << x.f+1 << ' ' << x.s+1 << "->" << y.f+1 << ' ' << y.s+1 << endl;
    // }
    int flg=-1;
    for(int i=0;i<path.size();i++){
        pii now1=path[i].f,lst1=path[i].s;
        if(mp[lst1.f][lst1.s]!='.'){
            for(int j=i;j>flg;j--){
                pii now2=path[j].f,lst2=path[j].s;
                ans.push_back({{lst2.f,lst2.s},getdir(now2,lst2)});
            }
            // cout<< "OK"<< i<<' '<< flg <<endl;
            flg=i;            
        }
    }
    mp[path.back().s.f][path.back().s.s]='.';
    mp[path[0].f.f][path[0].f.s]='!';
}

bool check(pii tp){
    if(tp.f<0||tp.f>=n||tp.s<0||tp.s>=m||mp[tp.f][tp.s]=='#'||vis[tp.f][tp.s]) return false;
    return true;
}

void bfs(int x,int y){
    queue<pii> q;
    memset(vis,0,sizeof(vis));
    memset(prex,0,sizeof(prex));
    memset(prey,0,sizeof(prey));
    path.clear();
    q.push({x,y});
    vis[x][y]=1;
    prex[x][y]=-1;
    prey[x][y]=-1;
    while(!q.empty()){
        pii now=q.front();
        q.pop();
        if(mp[now.f][now.s]=='*'){
            while(prex[now.f][now.s]!=-1||prey[now.f][now.s]!=-1){
                pii lst={prex[now.f][now.s],prey[now.f][now.s]};
                path.push_back({now,lst});
                now=lst;
            }
            return ;
        }
        for(int i=0;i<4;i++){
            pii next={now.f+dir[i][0],now.s+dir[i][1]};
            if(check(next)){
                q.push(next);
                vis[next.f][next.s]=1;
                prex[next.f][next.s]=now.f;
                prey[next.f][next.s]=now.s;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='@'){
                bfs(i,j);
                if(path.size()==0){
                    cout << -1 << endl;
                    return 0;
                }
                creat();
            }
        }
    }
    cout << ans.size() << endl;
    for(auto [x,y]:ans){
        cout << x.f+1 << ' ' << x.s+1 << ' ' << y << endl;
    }

    return 0;
}