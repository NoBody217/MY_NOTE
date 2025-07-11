#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int t,nxt;
}E;

E edge[101010];
int head[1010];
int cnt=0;
int n,m;

void insert(int st,int to){
    edge[++cnt].t=to;
    edge[cnt].nxt=head[st];
    head[st]=cnt;
}

int ans[1010];
int inc[1010];
queue<int> q;

void tuopo(){
    for(int i=1;i<=n;i++){
        if(inc[i]==0) q.push(i);
    }
    int tot=0;
    while(!q.empty()){
        int x=q.front();
        ans[tot]=x;
        // cout << x << ' ' ;
        q.pop();
        tot++;
        for(int i=head[x];i!=-1;i=edge[i].nxt){
            inc[edge[i].t]--;
            if(inc[edge[i].t]==0) q.push(edge[i].t);
        }
    }
    if(tot!=n) cout << -1 ;
    else{
        for(int i=0;i<n;i++)
            cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin >> n >> m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a  >> b;
        inc[b]++;
        insert(a,b);
    }
    tuopo();

    return 0;
}