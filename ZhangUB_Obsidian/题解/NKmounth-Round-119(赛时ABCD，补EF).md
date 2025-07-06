# [比赛链接](https://ac.nowcoder.com/acm/contest/112543#question)
# A 来选队长
## 题意
- 两个小队，每个小队5人，降序输入每个人战斗力
- 每个队的总战斗力是队长战斗力两倍+其余人战斗力之和
- 请问是否存在一种选队长方案使得第一队战斗力大于第二队战斗力
## 思路
- 第一队取最大，第二队取最小，直接比较即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
    int sum1=0,sum2=0;
    for(int i=0;i<5;i++) {cin >> a[i];sum1+=a[i];}
    for(int i=0;i<5;i++) {cin >> b[i];sum2+=b[i];}
    if(sum1+a[0]>sum2+b[4])cout << "YES" ;
    else cout << "NO" ;
    return 0;
}
```
# B 抽我选的效率曲
## 题意
- 1000首歌曲代号为1~1000
- 5个人输入5个编号代表自己想选的歌曲，如果输入0代表放弃选取
- 如果全部放弃就从1000首歌里随机抽取，否则从选的歌曲里抽取
- 输入一个k，请输出第k首歌被选中的概率
## 思路
- 开一个vis统计每首歌被选的次数,开一个sum记录一共选了几首歌
- 如果sum=0说明都没选，概率为`1/1000`
- 如果sum恰好等于vis\[k]，概率为`1/1`
- 如果vis\[k]=0,概率为`0/1`
- 其他情况输出`vis[k]/sum`，记得gcd约分
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int vis[1020];
int main(){
    int t;
    cin >> t;
    while(t--){
        int tp,k;
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<5;i++){
            cin >> tp;
            if(tp!=0){
                vis[tp]++;
                sum++;
            }
        }
        cin >> k;
        if(sum==0)cout << "1/1000" << endl;
        else if(sum==vis[k])cout << "1/1"<< endl;
        else cout << vis[k]/gcd(sum,vis[k]) << '/' << (vis[k]==0?1:sum/gcd(sum,vis[k])) << endl;
    }
    return 0;
}
```
# C 睡前床边看LIVE
## 题意
- 一共有n个人，每个人会告诉你除自己以外的n-1个中最大同色组的大小K
- 请判断他们说没说谎
## 思路
- 显然，n个答案中至多有两种K
- 对于所有人回答相同的情况
    1. 可以是所有人颜色相同，此时K=n-1
    2. 至少有两种颜色他们最大且数量相同，此时2K<=n
- 对于有两种不同回答的情况，只有一种颜色是最多的K，另一个答案一定是K-1,且回答为K的一定是K-1
## 代码
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    if (cnt.size() > 2) {
        cout << "Lie\n";
    } else if (cnt.size() == 1) {
        int K = cnt.begin()->first;

        if (K == n - 1) {
            cout << "Other\n";
        } else {
            if (2 * K > n) {
                cout << "Lie\n";
            } else {
                cout << "Other\n";
            }
        }
    } else { // cnt.size() == 2
        auto it = cnt.begin();
        int A = it->first;
        int num_A = it->second;
        it++;
        int B = it->first;

        if (B != A + 1) {
            cout << "Lie\n";
        } else if (num_A != B) {
            cout << "Lie\n";
        } else {
            cout << "Other\n";
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```
# D 世界树上找米库
## 题意
- 一颗n个结点的无根树，所有度为1的点记为sekai点
- 你需要找到这个树上miku点的个数，并升序输出编号
- miku点定义如下，度大于1，距离最近的sekai点距离最远
## 思路
- 对于这棵树，我们希望知道每一个点距离他最近的sekai点是谁
- 就需要对每一个点bfs一遍，显然$O(N^2)$不可行
- 由于每个点在第一次遇到sekai点后就不需要搜索了
- 可以直接从所有sekai点开始多源bfs
    - 一次性将所有sekai点扔进队列
    - 同时向外延伸
    - 每个点第一次被搜索到的时候他和父亲的sekai相同，距离加一
    - 直到所有点都被访问
- bfs后得到每个点的距离，输出即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> G[202020];
vector<int> sekai;
vector<int> miku;
pii fa[202020];
int vis[202020];
void bfs(){
    queue<int> q;
    for(int i=0;i<sekai.size();i++){
        q.push(sekai[i]);
        fa[sekai[i]].first=sekai[i];
        fa[sekai[i]].second=0;
        vis[sekai[i]]=1;
    
    }
    while (!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(auto i :G[tmp]){
            if(!vis[i]){
                q.push(i);
                fa[i].first=fa[tmp].first;
                fa[i].second=fa[tmp].second+1;
                vis[i]=1;
            }
        }
    }
}
int cmp(pii a, pii b){
    return a.second>b.second;
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        miku.clear();
        sekai.clear();
        
        int n;
        cin >> n;
        for(int i=0;i<=n;i++) {G[i].clear();fa[i].first=0;fa[i].second=0;}
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b ;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(G[i].size()==1)
                sekai.push_back(i);
        }

        bfs();
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(fa[i].second,mx);
        }
        for(int i=1;i<=n;i++){
            if(fa[i].second==mx) miku.push_back(i);
        }
        cout << miku.size() << endl;
        sort(miku.begin(),miku.end());
        for(int i=0;i<miku.size();i++){
            cout << miku[i] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
```