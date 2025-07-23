- 100多个AK的佬，牛逼
# A	题解的token计算
## 题意
- 输入一个数 $score$，输出 $150*ln(score)$
- 误差不超过1e-3
## 思路
- 直接硬搞，用printf格式化输出更方便
## 代码
```cpp
#include<bits/stdc++.h>

using namespace std;
int main(){
    double a;
    scanf("%lf",&a);
    printf("%lf",150*log(a));
}

```
# B 76修地铁
## 题意
1. 从第5列开始，每5列需要2个a
2. 从第5列开始，每10列需要1个b
3. 从第20列开始，每20列需要3个c
4. 从第1列开始，除了放置普通铁轨的那列，每列需要2个d
- [示意图链接](https://ac.nowcoder.com/acm/contest/113313/B)
## 思路
- 直接按题意输出即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << n/5*2 << ' ';
    cout << (n+5)/10 << ' ';
    cout << n/20*3 << ' '; 
    cout << 2*(n-(n/20)) << endl;
    return 0;
}
```
# C 76选数
## 题意
- 给定数字n
- 从小于n的数中任选，每个数只能选一次，将这些数字按位异或得到ans
- 求出最大的ans
## 思路
- 二进制拆位思考，一定能n的最高位及以下的所有位都可以用一个数表示
- ans就是`(1<<(n最高位))-1`
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long n;
    cin >> n;
    int cnt=0;
    while(n){
        n>>=1;
        cnt++;
    }
    cout << (1ull<<cnt)-1 << endl;
    return 0;
}
```
# D 76构造
## 题意
- 给定n，m
- 从n的某一个排列中任选若干个不相交连续区间，能否使得每个区间的gcd的或和为m？
- 如果可以，输出排列，以及每个区间的左右端点
## 思路
- 观察可得，n的排列中一定有1，和1在一个区间的这些数gcd后一定是1，所以偶数不可表示
- 二进制来看，n的排列的gcd一定不会大于n，所以如果m的位数比n更高也不可表示
- 剩下的一定可以表示，总可以用一个数表示m的某一二进制位
- 用若干数表示完m后剩下的全扔给1所在区间即可
## 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

int gt(int x){
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans;
}
int vis[102020];
int ans[102020];
int main(){
    int n,m;
    cin >> n >> m;
    int szn=gt(n),szm=gt(m);
    // cout << szn << ' ' << szm << endl;
    if(szn<szm||m%2==0) cout << -1 << endl;
    else{
        int cnt=0;
        for(int i=szm-1;i>0;i--){
            if((m>>i)&1){
                ans[++cnt]=(1<<i);
                vis[1<<i]=1;
            }
        }
        int cnt2=cnt;
        for(int i=1;i<=n;i++){
            if(vis[i]==0) ans[++cnt2]=i;
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
        cout << cnt+1 << endl;
        for(int i=1;i<=cnt;i++){
            cout << i << ' ' << i << endl;
        }
        cout << cnt+1 << ' ' << n << endl;
    }
    return 0;
}
```
# E qcjj寄快递
## 题意
- 二维平面n个点对，相邻两个点有一个欧氏距离，耗时为 $t_i=2k_i+2⋅dis_i/2k_i$
- 对这n-1个距离，请让 $\sum t_i$最小，输出这个结果
## 思路
- 高中数学：对于t关于k求导，得到最小值点 $log_2(ln2*\sqrt {dis})$
- 考虑实际意义，如果这个点小于0就取0
- 回带输出结果就行
## 代码
```cpp
#include<bits/stdc++.h>
#define pdd pair<double,double>
using namespace std;
pdd a[101010];
double dis2[101010];
double t[101010];
double cal(int x,int y){
    return fabs((a[x].first-a[y].first)*(a[x].first-a[y].first)+(a[x].second-a[y].second)*(a[x].second-a[y].second));
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;   
        if(i>=2){
            dis2[i]=cal(i,i-1);
            t[i]=2*max(0.0,(log2(log(2)*sqrt(dis2[i]))))+2*sqrt(dis2[i])/pow(2,max(0.0,(log2(log(2)*sqrt(dis2[i])))));
        }
    }
    double ans=0;
    for(int i=2;i<=n;i++){ans+=t[i];}
    printf("%.18lf",ans);

    return 0;
}
```
# F 幂中幂plus
## 题意
- 给定 $base$,$c_0$,$mod$
- 对于i>0,$c_i=pow(base,c_{i-1})\%mod$
- 对于q次询问，每次回答 $\sum _{i=1} ^{k}{c_i}$
## 思路
- 题目范围给出mod小于1e6,所以结果最多只有1e6种，剩下的一定会进入一个循环
- 暴力枚举所有情况
- 对于每次询问分类讨论
## 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

using ll=long long;

ll bas,c0,p;
int vis[1010110];
ll a[1010110];

ll qpow(ll a,ll b){
    a%=p;
    ll res=1;
    while(b){
      if(b&1) res=res*a%p;
      a=a*a%p;
      b>>=1;
    }
    return res;
}


int main(){
    cin >> bas >> c0 >> p;
    ll pre=c0,head=0,T=0,T_val;
    int cnt=1;
    while(true){
        ll nxt=qpow(bas,pre);
        // cout << pre << ' ' << nxt << endl;
        if(vis[nxt]){
            head=vis[nxt]-1;
            T=vis[pre]-vis[nxt]+1;
            T_val=(a[cnt-1]-a[head]+p)%p;
            break;
        }else{
            vis[nxt]=cnt;
            a[cnt]=(nxt+a[cnt-1])%p;
            cnt++;
        }
        pre=nxt;
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        ll k;
        cin >> k;
        if(k<cnt) cout << a[k]%p << endl;//不到一圈
        else{
            //超出一圈算：圈之前的，有几圈，剩下的但不足一圈的
            ll ans=0;
            k-=head;
            ans+=a[head];
            ans+=((k/T)%p)*(T_val%p);
            ans%=p;
            ll res=k%T;
            ans+=(a[head+res]-a[head]+p)%p;
            ans%=p;
            cout << ans << endl;
        }
    }
}
```