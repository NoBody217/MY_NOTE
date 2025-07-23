#include<bits/stdc++.h>
using namespace std;

struct ty{
    int t,l,nxt;
}edge1[5050];
ty edge2[5050];
int head1[10050],cnt1;
int head2[10050],cnt2;
int n,m;
long long ans[10050];
const int p=1000000007;

void insert1(int a,int b,int v){
    edge1[++cnt1].l=v;
    edge1[cnt1].t=b;
    edge1[cnt1].nxt=head1[a];
    head1[a]=cnt1;
}
void insert2(int a,int b,int v){
    edge2[++cnt2].l=v;
    edge2[cnt2].t=b;
    edge2[cnt2].nxt=head2[a];
    head2[a]=cnt2;
}

long long cnt[10050],dis[10050],vis[10050];

void init(){
    memset(head2,-1,sizeof(head2));
    cnt2=0;
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
}

struct cmp{
    bool operator() (const int &a,const int &b)const{
        return dis[a]>dis[b];
    }
};

void dij(int x){
    dis[x]=0,cnt[x]=1;
    priority_queue<int,vector<int>,cmp> q;
    q.push(x);
    while(!q.empty()){
        int tp=q.top();
        q.pop();
        if(vis[tp])continue;
        vis[tp]=1;
        for(int i=head1[tp];i!=-1;i=edge1[i].nxt){
            if(dis[edge1[i].t]==dis[tp]+edge1[i].l){
                cnt[edge1[i].t]+=cnt[tp];
                cnt[edge1[i].t]%=p;
                insert2(edge1[i].t,tp,i);
            }else if(dis[edge1[i].t]>dis[tp]+edge1[i].l){
                head2[edge1[i].t]=-1;
                insert2(edge1[i].t,tp,i);
                dis[edge1[i].t]=dis[tp]+edge1[i].l;
                cnt[edge1[i].t]=cnt[tp];
                cnt[edge1[i].t]%=p;
                q.push(edge1[i].t);
            }
        }
    }
}

int inc[10050],cntt[10050];

void tuopu(){
    //计算inc
    memset(inc,0,sizeof(inc));
    for(int i=1;i<=n;i++){
        cntt[i]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=head2[i];j!=-1;j=edge2[j].nxt){
            inc[edge2[j].t]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inc[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int tp=q.front();
        q.pop();
        for(int i=head2[tp];i!=-1;i=edge2[i].nxt){
            ans[edge2[i].l]+=(cnt[edge2[i].t]*cntt[tp])%p;
            ans[edge2[i].l]%=p;
            cntt[edge2[i].t]+=cntt[tp];
            inc[edge2[i].t]--;
            if(inc[edge2[i].t]==0){
                q.push(edge2[i].t);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(head1,-1,sizeof(head1));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++){
        int x,y,val;
        cin >> x >> y >> val;
        insert1(x,y,val);
    }
    for(int i=1;i<=n;i++){
        init();
        dij(i);
        tuopu();
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << endl;
    }
    return 0;
}