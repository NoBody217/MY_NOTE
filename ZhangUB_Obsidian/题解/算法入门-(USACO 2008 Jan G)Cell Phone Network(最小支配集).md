#dfs #动态规划 #树状dp #最小支配集
# 最小支配集
- 选择一个点，可以覆盖相邻的点，覆盖所有点所需最小选点
# 题意
- 给定一颗n个结点的树，求最小支配集
# 思路
- 考虑每一个点，他可能被支配的方式有：被父亲支配，选自己，被儿子支配，维护一个二维dp数组记录点和状态：$dp[i][0/1/2]$
* 自己：$dp[i][0]=\sum(min(dp[u][0],dp[u][1],dp[u][2]))+1$
* 父亲：$dp[i][1]=\sum min(dp[u][0],dp[u][2])$
* 儿子：$dp[i][2]=\sum min(dp[u][0],dp[u][2])$
* 对于自己和父亲，状态方程很显然可以推出，对于被儿子支配的情况，所有儿子不能依靠父亲，只能靠自己或者靠儿子的儿子，但是，总归有一个儿子需要靠自己，不然就无法覆盖父亲，所以，维护$min(dp[u][0]-dp[u][2])$，如果最终结果大于0,说明全都靠的儿子的儿子，需要补上一个靠儿子和自己的差值inc
* 对于inc，如果小于0，说明一定有一个$dp[u][0]$被选了，不用再依靠inc，所以每次inc>0后，将inc加入$dp[i][2]$
* **特别的**，对于叶子节点，由于inc初值赋的极大值，所以叶子节点的$dp[i][2]$被赋值为极大值，恰好表示叶子节点无法依靠儿子
* ==**警示后人：对于最终的结果，是输出所选定的根的最小支配，而根是没有父亲的，所以最终的结果只能从靠自己和靠儿子中取min(dp\[1]\[0],dp\[1]\[2])**==
# 代码
```cpp
#include<bits/stdc++.h>

using namespace std;
int dp[101010][3];
vector<int> a[101010];
void dfs(int x,int fa){
    dp[x][0]=1;
    int inc=0x3f3f3f3f;
    for(auto i :a[x]){
        if(i==fa)continue;
        dfs(i,x);
        dp[x][0]+=min(dp[i][0],min(dp[i][1],dp[i][2]));
        dp[x][1]+=min(dp[i][0],dp[i][2]);
        dp[x][2]+=min(dp[i][0],dp[i][2]);
        inc=min(dp[i][0]-dp[i][2],inc);
    }
    if(inc>0) dp[x][2]+=inc;
}

int main(){
    memset(dp,0,sizeof(dp));
    int n;
    cin >> n ;
    for(int i=1;i<n;i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    cout << min(dp[1][0],dp[1][2]);
    return 0;
}
```