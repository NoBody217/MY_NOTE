- 300多AK，输TT
- 背景：不动点
    - 一个序列中的元素，当且仅当 $a_i=i$ 认为是一个不动点
    - 一个矩阵中的元素，当且仅当 $a_{ij}=min(i,j)$ 认为是一个不动点
# A
## 题意
- 长为4的序列，输出其中的不动点个数
## 思路
- 签到，直接模拟
## 代码
```cpp
int main(){
    int cnt=0;
    for(int i=1;i<=4;i++){
        int tmp;
        cin >> tmp;
        if(tmp==i)cnt++;
    }
    cout << cnt ;
    return 0;
}
```
# B
## 题意
- 构造一个长为n有k个不动点的排列
## 思路
- 观察发现k=n-1就寄了
- 正解：先把前k个按顺序放，后面的错一位放 1，2，……k，k+2，……n，k+1
- 搞了复杂的倒着放然后分奇偶特判
## 代码
```cpp
int main(){
    int n,k;
    cin >> n >> k;
    if(k==n-1)cout << -1 << endl;
    else if(n%2&&k==0){
        cout << n <<' ';
        for(int i=1;i<=n-1;i++){
            cout << i <<' ' ;
        }
    }else if(n%2==0&&k==1){
        cout << 1 <<' ';
        cout << n <<' ';
        for(int i=2;i<=n-1;i++){
            cout << i <<' ' ;
        }        
    }else{
        for(int i=1;i<=k;i++){
            cout << i << ' ';
        }
        for(int i=n;i>k;i--){
            cout << i << ' ';
        }
    }
    return 0;
}
```
# C
## 题意
- 给2n个元素，划分成两组，想知道两组不动点数量和最大是多少
## 思路
- 一个元素出现的次数和2取min就是贡献，开个桶存就行
## 代码
```cpp
int main(){
    map<int,int> mp;
    int n;
    cin >> n;
    for(int i=1;i<=2*n;i++){
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    int ans=0;
    for(auto[x,y]:mp){
        if(x>n)break;
        ans+=min(y,2);
    }
    cout << ans << endl;
    return 0;
}
```
# D
## 题意
- 给定一个n\*m的矩阵，你可以进行一次操作使得两个元素交换
- 求解最大的矩阵不动点数量
## 思路
- 最开始看错范围了写了个 $O(n^2)$ 的暴力，遂T
- 已经在不动点上的不用动，直接给ans++
- 不在不动点上的记录下来，同时用一个bool数组st记录所有的不在不动点上的状态 $(a_{ij},min(i,j))$
- 开一个lie数组记录st每一列的状态
- 遍历b中的元素，每一个检查有没有匹配的st，如果有直接输出ans+2
- 同时开一个flg记录能不能+1
## 代码
```cpp
int a[505][505];
vector<pair<int,int>> b;
bool mp[505][505];
bool lie[505];
//250000
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]==min(i,j)){
                ans++;
            }else{
                b.push_back({a[i][j],min(i,j)});
                mp[a[i][j]][min(i,j)]=1;
                lie[min(i,j)]=1;
            }
        }
    }
    int flg=0;
    for(auto p:b){
        if(mp[p.second][p.first]){
            cout << ans+2 << endl;
            return 0;
        }
        if(lie[p.first]){
            flg=1;
        }
    }
    cout << (ans+flg) << endl;
    return 0;
}
```
# E
## 题意
- 一个长为n的数组，求所有子数组中的不动点最大个数的和
## 思路
- **考虑对每一个数算贡献**
- 对于1，能产生贡献的左右界分别是1左边和1右边，相乘即可
- 对于2，能产生贡献的左右界分别是1，2位置小的左边，1，2位置大的右边
- 综上每一个数产生贡献的左右界是它和所有比它小的数位置最靠左的和最靠的
- 记录每个数的位置然后从小到大增加贡献即可
## 代码
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[303030];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n; 
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        p[x]=i;
    }
    long long ans = 0;
    int mn=n+1,mx=0;
    for(int i=1;i<=n;i++){
        mn=min(mn,p[i]);
        mx=max(mx,p[i]);
        ans+=mn*(n-mx+1);
    }
    cout << ans << '\n';
    return 0;
}
```
# F
## 题意
- 一个n个点的数，求所有子树中不动点最大个数的和
## 思路
- 一个子树想产生贡献，一定包含结点1
- 一个子树想产生贡献2，一定包含1，2
- 此时可选的最小结点是lca(1,2)，1，2产生的贡献是dep\[lca(1,2)]
- 继续递推发现lca不断上移至fa\[lca]
- 同理递推下去即可知道所有贡献
- 对树做一个dfn，做树链剖分，同时树形dp统计size，dep，fa，这样可以在 $O(1)$ 的时间知道一个结点是否属于一个子树
- 最后从1开始不断上跳lca并统计答案即可
- 
## 代码
```cpp
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

vector<int> G[202020];
int idx[202020],f[202020],sz[202020],dep[202020];
int tim;

int dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    sz[x]=1;
    tim++;
    idx[x]=tim;
    f[x]=fa;
    for(auto y:G[x]){
        if(y==fa) continue;
        sz[x]+=dfs(y,x);    
    }
    return sz[x];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(n,0);
    int lca=1,ans=0;
    for(int i=1;i<=n;i++){
        while(lca<=0||!(idx[lca]<=idx[i]&&idx[i]<=idx[lca]+sz[lca]-1)){
            lca=f[lca];
        }
        ans+=dep[lca];
    }
    cout << ans << endl;
    return 0;
}
```