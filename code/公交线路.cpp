#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int t,l,nxt;
}E;

E edge[101010];
int head[101010];
int cnt;
int n,m,s,t;
int dis[1010],vis[1010];

void insert(int x,int y,int val){
    edge[++cnt].t=y;
    edge[cnt].l=val;
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}

queue<int> q;
int spfa(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i!=-1;i=edge[i].nxt){
            int y=edge[i].t;
            if(dis[y]>dis[x]+edge[i].l){
                dis[y]=dis[x]+edge[i].l;
                if(!vis[y]){
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
    }
    if(dis[t]>=0x3f3f3f3f) return -1;
    else return dis[t];
}

int main(){
    cin >> n >> m >> s >> t;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int a,b,v;
        cin >> a >> b >> v;
        insert(a,b,v);
        insert(b,a,v);
    }
    cout << spfa(s,t) << endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;


// typedef struct{
//     int t,l,nxt;
// }E;

// struct ty{
//     int x,dis;
//     bool operator < (const ty &a) const{
//         return dis > a.dis;
//     }
// };

// E edge[101010];
// int n,m,s,t;
// int dis[1010],vis[1010];
// int head[1010];
// int cnt=0;

// void insert(int x,int y,int val){
//     edge[++cnt].t=y;
//     edge[cnt].l=val;
//     edge[cnt].nxt=head[x];
//     head[x]=cnt;

// }

// priority_queue<ty> q;
// int dijkstra(int st,int to){
//     dis[st]=0;
//     ty tmp;
//     tmp.x=s,tmp.dis=0;
//     q.push(tmp);
//     while(!q.empty()){
//         ty tp=q.top();
//         q.pop();
//         if(vis[tp.x]) continue;
//         vis[tp.x]=1;
//         for(int i=head[tp.x];i!=-1;i=edge[i].nxt){
//             int to=edge[i].t;
//             if(vis[to]) continue;
//             if(dis[to]>dis[tp.x]+edge[i].l){
//                 dis[to]=dis[tp.x]+edge[i].l;
//                 ty tp2;
//                 tp2.x=to,tp2.dis=dis[to];
//                 q.push(tp2);
//             }
//         }

//     }
//     if(dis[t]>=0x3f3f3f3f) return -1;
//     else return dis[to];
// }

// int main(){
//     cin >> n >> m >> s >> t;
//     memset(head,-1,sizeof(head));
//     memset(dis,0x3f,sizeof(dis));
//     for(int i=1;i<=m;i++){
//         int a,b,v;
//         cin >> a >> b >> v;
//         insert(a,b,v);
//         insert(b,a,v);
//     }
//     cout << dijkstra(s,t) << endl;

//     return 0;
// }