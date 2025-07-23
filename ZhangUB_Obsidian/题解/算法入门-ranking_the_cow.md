#位运算优化 #floyd传递闭包
# 题意
- n个数，确定了m对关系(a>b)
- 求还需要多少对关系就能确定任意两个数之间的大小
# 思路
- 把大小关系视为一条有向边
- 这个题就变成了任意两个点是否联通
- 考虑使用FLoyd，但是n是1000量级的，刚好爆炸
- 使用bitset优化 $O(n/64)$ 足够
- floyd算法可以传递闭包关系
# 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

bitset<1010> f[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        f[x][y]=1;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(f[i][j]){
                f[i]|=f[j];
            }
        }
    }
    int ans=n*(n-1)/2;
    for(int i=1;i<=n;i++){
        ans-=f[i].count();
    }
    cout << ans << endl;
    return 0;
}
```
