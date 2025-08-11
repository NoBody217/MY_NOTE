- A题和C题犯蠢，A看半天没看出来，在那里写模拟，C以为暴力会爆炸，结果不会，G是个神奇乱搞
# A
## 题意
- 当一个01串任意的相邻两个字符不一样时称为好串
- 给定n输出长度为n的好串个数
## 思路
- 一共只有两种，别想复杂了，输出2就行
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;
    cin >> n;
    cout << 2 << endl;
    return 0;
}
```
# B
## 题意
- 一个01串中有三个1，判断中间的1和两边的1是否相等
## 思路
- 扫一遍模拟即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    int flg[3];
    int cnt=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            flg[cnt++]=i;
        }
    }
    cout << ((flg[1]-flg[0]==flg[2]-flg[1])?"Yes":"No") << endl;
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
- T组(T<=1000)，每组给定一个长度为n的01串(N<=2e5)
- 每次操作可以flip任意两个相同的字符
- 求把原串变为好串的最少次数
## 思路
- 最开始以为是小巧思，观察了半天数学规律没观察出来
- 已知一共只有两种串，直接模拟变为两种串需要的操作次数
- 模拟到倒数第二位的时候停止，如果最后一位和上一位相同，就说明不行
- 如果可以变为好串，两种方案取min就行
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    string s1=s,s2=s;
    int cnt1=0,cnt2=0;
    for(int i=1;i<n;i++){
        if(s1[i]!=i%2+'0'){
            cnt1++;
            s1[i]='1'-s1[i]+'0';
            s1[i+1]='1'-s1[i+1]+'0';
        }
    }
    if(s1[n]==s1[n-1]) cnt1=INT32_MAX;
    for(int i=1;i<n;i++){
        if(s2[i]!=(i+1)%2+'0'){
            cnt2++;
            s2[i]='1'-s2[i]+'0';
            s2[i+1]='1'-s2[i+1]+'0';
        }
    }
    if(s2[n]==s2[n-1]) cnt2=INT32_MAX;    
    // cout << s << endl << s1 <<endl << s2 << endl;
    int ans=min(cnt1,cnt2);
    cout << (ans==INT32_MAX?-1:ans) << endl;    
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
# D
## 题意
- 给定01串，长度不超过500，每次操作可以翻转某一位
- 求最少的翻转次数，使得count("01")+coune("10")=3
## 思路
- 满足要求的串只有两种类型"1…10…01…10…0"和"0…01…10…01…10…0"
- 一共就是4段，使用i,j,k标记后三个块的开始，同时维护一个前缀0个数一个前缀1个数，这样就可以 $O(n^3)$ 暴力得出答案
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
/**
 * 只要0101，1010
 */
int cnt0[600],cnt1[600];
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cnt0[i]=cnt0[i-1]+(s[i]=='0');
        cnt1[i]=cnt1[i-1]+(s[i]=='1');
    }
    int ans=0x3f3f3f3f;
    for(int i=2;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                ans=min(ans,
                    min(cnt0[i-1]+(cnt1[j-1]-cnt1[i-1])+(cnt0[k-1]-cnt0[j-1])+(cnt1[n]-cnt1[k-1]),
                    cnt1[i-1]+(cnt0[j-1]-cnt0[i-1])+(cnt1[k-1]-cnt1[j-1])+(cnt0[n]-cnt0[k-1])));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
```
# E
## 题意
- 对于一个01串它的权值记为由'1'构成的连续字串的数量
- T组(T<=1e5)，每组给定一个正整数k(k<=2e5)，求最短的权值为k的01串的长度
## 思路
- 先打个表,发现权值在2e5内的连续1段的个数只有不到650个
- 由题意，我们希望段数尽可能少，但又不是优先取最大价值
- 换一种想法，一个连续1段的权值是固定的，不同长度权值不同，要用不同权值凑出一个指定权值，种类不多，可以按完全背包做，权值视为体积长度视为价值
- 更新的时候每段要认为带着一个0，最后总答案再减去一个0

## 代码
```cpp
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


vector<pii> tb;
int dp[202021];

void solve(){
    int n;
    cin >> n;
    cout << dp[n]-1 << endl;
}

int main(){
    memset(dp,0x3f,sizeof(dp));
    int p=202020;
    dp[0]=0;
    for(int i=1;i*(i+1)/2<=p;i++){
        tb.push_back({i*(i+1)/2,i});
    }
    for(int i=0;i<tb.size();i++){
        for(int j=1;j<=202020;j++){
            if(j-tb[i].first<0)continue;
            dp[j]=min(dp[j],dp[j-tb[i].first]+tb[i].second+1);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
# F
## 题意
- 同上，但是输出所获得的01串
## 思路
- 开一个path记录到达每一个体积时加入的价值即可
## 代码
```cpp
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/**
 * 背包
 */

vector<pii> tb;
int dp[202021];
vector<int> path(202021);
int pre;
void solve(){
    int n;
    cin >> n;
    while(n>0){
        int len=path[n];
        n-=len*(len+1)/2;
        cout << string(len,'1');
        if(n!=0)cout << '0';
    }
    cout << endl;

}

int main(){
    memset(dp,0x3f,sizeof(dp));
    int p=202020;
    dp[0]=0;
    for(int i=1;i*(i+1)/2<=p;i++){
        tb.push_back({i*(i+1)/2,i});
    }
    for(int i=0;i<tb.size();i++){
        for(int j=1;j<=202020;j++){
            if(j-tb[i].first<0)continue;
            if(dp[j-tb[i].first]+tb[i].second+1<dp[j]){
                dp[j]=dp[j-tb[i].first]+tb[i].second+1;
                path[j]=tb[i].second;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
# G
## 题意
- 给定长度为n的数组(n<=2.5e5)，处理q次询问(q<=2.5e5)
- 每次查询(l,r)，回答(l,r)是不是一个双排列(里面有两个相同的排列)
## 思路
- **神奇做法——哈希**
- 通过若干必要条件约束来使得满足条件大概率成立，约束越多，必要条件约接近充要条件
    - 区间长度偶数
    - 区间所有数数出现偶数次
    - 区间和是len\*(len+1)
    - 区间平方和是len\*(len+3)\*(2len+1)/3
    - ……
- 对于区间所有数出现偶数次使用的是异或哈希
    - 每个数出现偶数次，异或和必然为0
    - 把所有数哈希到一个大整数(因为小整数可能刚好出现次数不满足，但异或和为0，如1,2,3)
    - 前缀和即可
- 对于有可能满足这些必要条件，但是又不是双排列的数据，一定出现在长度较小的情况，因为长度越长构造约难
- 所以小数据的时候直接暴力搞，大数据哈希搞
- **记得开long long**
## 代码
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;

std::mt19937 rng;
int rand(int l,int r){//int随机数生成
    std::uniform_int_distribution<int> distribution(l,r);
    return(distribution(rng));
}

vector<int> a(252525);
vector<int> sum1(252525);
vector<int> sum2(252525);
vector<int> ha(252525);
vector<int> pre(252525);
signed main(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+a[i]*a[i];
    }

    for(int i=1;i<=202020;i++){
        ha[i]=rand(1,1e18);
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^ha[a[i]];
    }

    while(q--){
        bool ok=1;
        int l,r;
        cin >> l >> r;
        int len=r-l+1;
        if(len%2){
            cout << "No" << endl;
            continue;
        }else{
            len/=2;
            if(len<=500){
                vector<int> cnt(len+1);
                bool ok=1;

                for(int i=l;i<=r;i++){
                    if(a[i]>len){
                        ok=false;
                        break;
                    }
                    cnt[a[i]]++;
                }
                if(!ok){
                    cout << "No" << endl;
                    continue;
                }

                for(int i=1;i<=len;i++){
                    if(cnt[i]!=2){
                        ok=false;
                        break;
                    }
                }
                cout << (ok?"Yes":"No") << endl;
            }else{
                if(pre[l-1]^pre[r]){
                    cout << "No" << endl;
                    continue;
                }
                int jg1=len*(len+1);
                if(sum1[r]-sum1[l-1]!=jg1){
                    cout << "No" << endl;
                    continue;
                }
                int jg2=len*(len+1)*(2*len+1)/3;
                if(sum2[r]-sum2[l-1]!=jg2){
                    cout << "No" << endl;
                    continue;
                }
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
```