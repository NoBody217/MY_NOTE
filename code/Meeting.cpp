#include<bits/stdc++.h>

using namespace std;

struct ty{
    int t,l,nxt;
}edge[2020220];
int head[2020220];
int cnt;
void insert(int a,int b,int v){
    edge[++cnt].t=b;
    edge[cnt].l=v;
    edge[cnt].nxt=head[a];
    head[a]=cnt;
}

int n,m;
long long dis1[2020220],dis2[2020220],vis[2020220];

struct cmp1{
    bool operator () (const int &a,const int &b) const{
        return dis1[a]>dis1[b];
    }
};
struct cmp2{
    bool operator () (const int &a,const int &b) const{
        return dis2[a]>dis2[b];
    }
};
priority_queue<int,vector<int>,cmp1> pq1;
priority_queue<int,vector<int>,cmp2> pq2;

int main(){
    int t;
    cin >> t;
    for(int group=1;group<=t;group++){
        cnt=0;
        memset(head,-1,sizeof(head));
        cin >> n >> m;
        int id=n;//每个集合要裂出一个点
        for(int i=1;i<=m;i++){
            id++;
            int t,num;
            cin >> t >> num;
            for(int i=1;i<=num;i++){
                int tmp;
                cin >> tmp;
                insert(tmp,id,t);
                insert(id,tmp,0);
            }
        }
        //第一个dijkstra
        memset(dis1,0x3f,sizeof(dis1));
        memset(vis,0,sizeof(vis));
        dis1[1]=0;
        pq1.push(1);
        while(!pq1.empty()){
            int x=pq1.top();
            pq1.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=head[x];i!=-1;i=edge[i].nxt){
                int t=edge[i].t;
                if(vis[t])continue;
                if(dis1[t]>dis1[x]+edge[i].l){
                    dis1[t]=dis1[x]+edge[i].l;
                    pq1.push(t);
                }
            }
        }
        //第二个
        memset(dis2,0x3f,sizeof(dis2));
        memset(vis,0,sizeof(vis));
        dis2[n]=0;
        pq2.push(n);
        while(!pq2.empty()){
            int x=pq2.top();
            pq2.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=head[x];i!=-1;i=edge[i].nxt){
                int t=edge[i].t;
                if(vis[t])continue;
                if(dis2[t]>dis2[x]+edge[i].l){
                    dis2[t]=dis2[x]+edge[i].l;
                    pq2.push(t);
                }
            }
        }
        // for(int i=1;i<=n;i++) cout << dis1[i] << ' ' ;
        // cout << endl;
        // for(int i=1;i<=n;i++) cout << dis2[i] << ' ' ;
        // cout << endl;
        long long ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            ans=min(ans,max(dis1[i],dis2[i]));
        }
        cout << "Case #"<< group<< ": ";
        if(ans>=0x3f3f3f3f) cout << "Evil John" << endl;
        else{
            cout << ans << endl;
            vector<int> tp;
            for(int i=1;i<=n;i++){
                if(max(dis1[i],dis2[i])==ans)
                    tp.push_back(i);
            }
            for(auto i:tp){
                cout << i << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}