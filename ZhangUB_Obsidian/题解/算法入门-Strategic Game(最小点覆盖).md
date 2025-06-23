#动态规划 #树状dp #dfs #最小点覆盖
# 最小点覆盖
- 选择一个点，覆盖所有相邻边，最少选几个点能覆盖所有边
# 题意
- 给定一棵n个结点的树，选定一个结点后即可覆盖他的所有邻边，求覆盖所有邻边的最少选定结点数
# 思路
- 动态规划，考虑每一个点
- 对于每一个结点，由于覆盖边，所以自己考虑选和不选两种情况，且父亲没选，自己就一定得选，父亲选了，自己就可选可不选，**注意区分最小点覆盖，最小边覆盖，最小支配集**
* $dp[i][1]=\sum(min(dp[u][0],dp[u][1])+1$
* $dp[i][0]=\sum dp[u][1]$
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

/**
 * dp[i][0/1];表示自己不选，自己选
 * dp[i][1]=sum(min(dp[u][0],dp[u][1])+1;
 * dp[i][0]=sum(dp[u][1]);
 */

vector <int> son[2000];
int dp[2000][2];
void dfs(int x,int fa){
    dp[x][1]=1;
    dp[x][0]=0;
    for(auto i : son[x]){
        if(i==fa) continue;
        dfs(i,x);
        dp[x][1]+=min(dp[i][0],dp[i][1]);
        dp[x][0]+=dp[i][1];
    }
}

int main(){
    int n ;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<2000;i++){
            son[i].clear();
        }
        int x,y,cnt ;
        for(int j=0;j<n;j++){
            scanf("%d:(%d)",&x,&cnt);
            for(int i=0;i<cnt;i++){
                scanf("%d",&y);
                son[x].push_back(y);
                son[y].push_back(x);
            }            
        }
        dfs(0,-1);
        cout << min(dp[0][0],dp[0][1]) << endl;
    }
    return 0;
}
```