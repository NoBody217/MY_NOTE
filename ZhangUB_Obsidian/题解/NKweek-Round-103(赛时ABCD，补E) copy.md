# A
## 题意
- 给出一个n，判断翻转后有没有前导0
## 思路
- 直接 mod 10就可以了
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n ;
    cout << (n%10?"YES":"NO") << endl;
    return 0;
}
```
# B
## 题意
- 判断一个01环有没有有没有可能单调不减
## 思路
- 模拟就行
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int a[202020];
void solve(){ 
    int cnt=0;
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==1&&a[i-1]==0&&i>=2) cnt++;
    }
    if(a[n]==0&&a[1]==1)cnt++;
    cout << (cnt<=1?"YES":"NO") << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
# C
## 题意
- 对于一个长度为n的排列，求解有多少种方案，使得它有n个子区间是一个排列
## 思路
- 观察得出，放置1后，剩下元素必须升序，每次放有两个位置可以放
- 答案就是 $2^{n-1}$ 
## 代码
```cpp
#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int p=1e9+7;

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;   
    cout << qpow(2,n-1) << endl;
}
```
# D
## 题意
- 对一个01串，你可以翻转任意一位，请问使得它至少有三个`01`，`10`最少需要多少次
## 思路
- 观察发现，最多两次操作就可以完成
- 如果超过三个01，就直接输出0
- 如果一个01段都没有，必然两次
- 剩下的全扫一遍模拟贡献即可
## 代码
# E
- 看了眼lca没做，导致掉大分
## 题意
- 一个有根树，每个结点权值为0或1
- 定义好路径：u->v，v->u权值拼接成的二进制串代表的十进制值为x，且lca(u,v)=u或lca(u,v)=v
- 给定q次询问，每次给定x，回答是否存在权值x的好路径
## 思路
- 所谓lca的部分其实就是这个路径是从某一个结点向上得到的
- 直接整个树跑一个搜索，搜到每一个点就不停地往上搜，每次将获得的权值加入vis
- 由于限制x小于等于 $2^{21}$ 最终每个点只需要向上搜21步，复杂度被控制在 $nlog(max_ele)$
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;


vector<int> G[101010];
vector<int> f(101010);
vector<int> vis(1<<22);
string v;

void dfs(int x,int fa){
    f[x]=fa;
    for(auto i:G[x]){
        if(i==fa)continue;
        dfs(i,x);
    }
    int dep=0;
    int s1=0,s2=0;
    while(dep<=21&&x!=0){
        s1=(s1<<1)+(v[x]-'0');
        s2=s2+((v[x]-'0')<<dep);
        x=f[x];
        dep++;
        vis[s1]=1;vis[s2]=1;
    }    
}
int main(){
    int n,q;
    cin >> n >> q;
    cin >> v;
    v=' '+v;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        cout << (vis[x]?"YES":"NO") << endl;
    }
    return 0;
}
```