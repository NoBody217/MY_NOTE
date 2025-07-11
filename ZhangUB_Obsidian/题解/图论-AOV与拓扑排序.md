# 引入
- 一个工程有许多子工程，称为活动，在有向图中用顶点表示活动，有向边表示活动的先后顺序，这样的图称为AOV网，在AOV网中为了更好的完成工程，需要满序先后关系，将各活动排一个先后次序，就称为拓扑排序
# 问题
- 对一个AOV图，判断能否排序，并进行排序
# 解决方法
- 从有向图中选一个没有前驱的结点，输出
- 从图中删除这个点以及所有出边
- 重复上述两步直至图为空，或者无法删除
- 注意，拓扑排序存在多解，可能同时存在两个没有前驱的结点
# 实现
- 开一个队列，把入度为0的点弹入，弹出队首，给邻接点入读减一，如果减成0,入队
- 对于每个点每个边都访问一次，O(nm)
```cpp
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
```
# 应用
- 判断有无环
