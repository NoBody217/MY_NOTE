#include<bits/stdc++.h>
using namespace std;

struct E{
    int t,nxt;
}edge[101010];
int head[101010];
int inc[101010];
int cnt;


int n,m;

void insert(int a,int b){
    edge[++cnt].t=b;
    edge[cnt].nxt=head[a];
    head[a]=cnt;
}

priority_queue<int> q;
int ans[101010];
int cnt1;
bool tuopu(){
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        if(inc[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.top();
        q.pop();
        ans[++cnt1]=x;
        for(int i=head[x];i!=-1;i=edge[i].nxt){
            inc[edge[i].t]--;
            if(inc[edge[i].t]==0){
                q.push(edge[i].t);
            }
        }
    }
    if(cnt1<n) return false;
    else return true;
}

int main(){
    int d;
    cin >> d;
    while(d--){
        cnt=cnt1=0;
        memset(head,-1,sizeof(head));
        memset(inc,0,sizeof(inc));
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            int a,b;
            cin >> a >> b;
            insert(b,a);
            inc[a]++;
        }
        if(!tuopu()) cout << "Impossible!" << endl;
        else{
            for(int i=n;i>=1;i--){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }

}