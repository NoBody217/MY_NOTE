#二进制拆位 #dp #深度优先搜索 
- 二进制按位拆贡献看太久，最后一题爆搜没敢写
# A
## 题意
- 给定k，输出两个非负整数使得异或和为k
## 思路
- 签到，0和k
## 代码
```cpp
int main(){
    int k;
    cin >> k;
    cout << 0 << ' ' << k << endl;
    return 0;
}
```
# B
## 题意
- 给定长为n的序列a，求相邻两个元素的异或和，获得长为n-1的序列b，求序列b的gcd
## 思路
- 直接模拟
## 代码
```cpp
int a[30];
int b[30];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        b[i]=a[i]^a[i+1];
    }
    int ans=b[0];
    for(int i=1;i<n-1;i++){
        ans=gcd(ans,b[i]);
    }
    cout << ans << endl;
    return 0;
}
```
# C
## 题意
- 构造n\*n的01矩阵，使得(每行元素的异或和的和)和(每列元素异或和的和)相加等于k
## 思路
- 观察发现，从全零开始填，对角线上每个位置可以贡献2
- 继续观察，发现填充任意位置都会同时影响行和列，不会影响总贡献的奇偶性
- 所以，奇数直接寄，偶数就在对角线上填即可
## 代码
```cpp
int maze[1010][1010];
int main(){
    int n,k;
    cin >> n >> k;
    if(k%2){
        cout << -1 << endl;
        return 0;
    } 
    int cnt=k/2;
    for(int i=1;i<=cnt;i++){
        maze[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << maze[i][j] ;
        }
        cout << endl;
    }
    return 0;
}

```
# D
## 题意
- 给定一个长为n的序列，其中只有1，2两个元素，你可以重排这个序列
- 能否使得相邻两个元素的gcd的和为k，如果可以输出序列，否则输出-1
## 思路
- 相邻两个元素gcd=2当且仅当序列为(2,2)，因此在得知序列中1和2的个数后可以计算整个序列可达的最大值和最小值
- 同时可以证明最大值和最小值之间的所有值都是可达的
- **构造方法**：计算序列最大值和k之间的差，填充这么多对21，剩下的2和1放一块一次性填充即可
## 代码
```cpp
int a[202020];
int main(){
    int n,k;
    cin >> n >> k;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==1) cnt1++;
        else cnt2++;
    }
    // cout << cnt1 << ' ' << cnt2 << endl;
    if(k>cnt1+(cnt2-1)*2){
        cout << -1 << endl;
        return 0;
    }
    else if(k<cnt1&&cnt1>=cnt2-1){
        cout << -1 << endl;
        return 0;
    }
    else if(k<cnt1+2*(cnt2-cnt1-1)&&cnt1<cnt2-1){
        cout << -1 << endl; 
        return 0;
    }else{
        int mxans=cnt1+2*(cnt2-1);
        int need=mxans-k;
        for(int i=1;i<=need;i++){
            cout << "2 1 " ;
            cnt1--;
            cnt2--;
        }
        for(int i=1;i<=cnt2;i++){
            cout << "2 ";
        }
        for(int i=1;i<=cnt1;i++){
            cout << "1 ";
        }
        cout << endl;
    }
    return 0;
}
```
# E
## 题意
- 一个n个点，m条无向边的联通图，每个顶点有权值
- 统计所有长为2的路径的异或和的和是多少
## 思路
- **经典处理：长为2路径——考虑中间点**
- **经典处理：异或和——考虑拆位计算贡献**
- 对于每一个结点，包含他的路径是以它为中心，从他的邻居中任选两个
- 同时，他的每一个二进制位产生的贡献是独立的
- 对于每一个二进制位
    - 如果当前位是1，则能产生贡献的对数是所有邻居中当前位是0的任选两位和所有邻居中当前位是1的任选两位
    - 如果当前位是0，则能产生贡献的对数是所有邻居中当前位是0和当前位是1的个数的乘积
- 整体复杂度 $O(32*2*m)每条边被遍历两遍，每次拆位$
## 代码
```cpp
using ll=long long;
const int p=998244353;

vector<int> G[202020];
int a[202020];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll cnt[2][32]={0};
        for(auto j:G[i]){
            for(int k=0;k<=31;k++){
                if((a[j]>>k)&1) cnt[1][k]++;
                else cnt[0][k]++;
            }
        }
        for(int j=0;j<=31;j++){
            ll tmp=0;
            if((a[i]>>j)&1){
                tmp=((cnt[0][j]*(cnt[0][j]-1))+(cnt[1][j]*(cnt[1][j]-1)))/2;
                ans+=(tmp*(1<<j))%p;
                ans%=p;
            }else{
                tmp=cnt[0][j]*cnt[1][j];
                ans+=(tmp*(1<<j))%p;
                ans%=p;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

```
# F
## 题意
- 构造一个长为n的数组，数组中元素的范围是1~m，使得数组的前缀gcd的前缀和为x
## 思路
- 最暴力的暴力，直接爆搜
- 从1~m枚举起点，dfs(cnt,now_gcd,now_val)
- dfs(1,i,i)往下转移：枚举j属于1~i，搜dfs(1,gcd(i,j),i+gcd(i,j))
- 最终会T，需要剪枝
    - 搜到发现剩下的位置全填充当前最大元素都不够x就直接跳出
    - 搜到当前和已经大于x就跳出
- 另一种做法，dp+还原，和上面的爆搜类似，但是记忆化搜索，如果相同的状态已经走过就不要再走了
## 代码
- 爆搜+剪枝
```cpp
#include<bits/stdc++.h>
using namespace std;
int a[55];
int n,m,x;
bool dfs(int cnt,int gd,int val){
    if(val+(n-cnt)*gd<x||val>x) return false;
    if(cnt==n){
        if(val==x) return true;
        else return false;
    }
    for(int i=gd;i>=1;i--){
        a[cnt+1]=i;
        if(dfs(cnt+1,gcd(gd,i),val+gcd(gd,i))){
            return true;
        }
    }
    return false;
}

void solve(){
    bool flg=0;
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++){
        a[1]=i;
        if(dfs(1,i,i)){
            flg=1;
            break;
        }
    }
    if(!flg) cout << -1;
    else{
        for(int i=1;i<=n;i++){
            cout << a[i] << ' ';
        }
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
```
- dp+还原
```cpp
#pragma gcc optimize(3)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct ty{
    int lstb,lstc,num;
};

bool dp[55][55][55*55];
ty pre[55][55][55*55];
bool flg=0;
int n,m,x;
/**
 * dp[i][j][k]第i位前缀gcd为j总权值k
 */


void dfs(int a,int b,int c){
    if(flg) return ;
    if(dp[a][b][c]) return;
    dp[a][b][c]=1;
    if(a>=n){
        if(c==x){
            vector<int> ans(n+10);
            int nb=b,nc=c;
            for(int i=n;i>=1;i--){
                flg=1;
                // cout << i << ' ' << nb << ' ' << nc << endl;
                auto now=pre[i][nb][nc];
                ans[i]=now.num;
                nb=now.lstb;
                nc=now.lstc;
            }
            for(int i=1;i<=n;i++){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        return ;
    }
    for(int i=1;i<=b;i++){
        pre[a+1][gcd(b,i)][c+gcd(b,i)]={b,c,i};
        dfs(a+1,gcd(b,i),c+gcd(b,i));
    }    
}

void solve(){
    flg=0;
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++){
        if(flg) break;
        pre[1][i][i]={0,0,i};
        dfs(1,i,i);
    }
    if(!flg) cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

```