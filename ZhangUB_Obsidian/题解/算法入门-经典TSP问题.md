#状压dp
# 题意
- 旅行商问题，在一个若干点的图中，设计一条最短路径，途径所有点
- 有时最终会要求回到原点
# 思路
- 状压dp
- 访问每一个点的时候需要考虑当前已经访问了哪些点
- 走到某一个点的最短路径应该是所有(上一步最短路径+上一步所在点到当前点距离)取最小
- $dp[st][i]$表示当前状态为st，最后一个点时i的最短路径
- $dp[st][i]=min(dp[st-(1<<(i-1))][j]+G[j][i])$
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1020;
/**
 * dp[st][i]表示当前状态为st，最后一个点时i的最短路径
 * dp[st][i]=min(dp[st-(1<<(i-1))][j]+G[j][i])
 */
int n,m;
int G[N][N];
int dp[(1<<20)+20][N];

int deal(int st,int x){
    if(dp[st][x]<=0x7f7f){//当前点有没有处理过
        return dp[st][x];
    }
    int st1=st-(1<<(x-1));//上一步状态
    for(int i=1;i<=n;i++){
        if((st1>>(i-1))&1&&G[i][x]!=0)//这个点在上一步走过，这个点到x存在边
            dp[st][x]=min(dp[st][x],deal(st1,i)+G[i][x]);
    }
    return dp[st][x];
}
int main(){
    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        int a,b,v;
        cin >> a >> b >> v;
        G[a][b]=G[b][a]=v;
    }
    memset(dp,0x7f7f,sizeof(dp));
    dp[1][1]=0;//起点
    int lst=(1<<n)-1;//最终状态
    int ans=0x7f;
    for(int i=2;i<=n;i++){//枚举终点
        ans=min(ans,deal(lst,i)+G[i][1]);//最后加上走回起点的路程 
    }
    cout << ans << endl;
    return 0;
}
/*
test case
5 9
1 2 2 
1 3 7
1 4 2
1 5 4 
2 3 10 
2 4 6
2 5 3
3 4 4
4 5 1
ans
17
*/
```