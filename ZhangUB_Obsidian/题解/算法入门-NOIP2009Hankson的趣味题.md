#质因数分解 #唯一分解定理 #数学
[贴一个大佬的题解](https://www.luogu.com.cn/article/4xtrh9ma)
# 题意
- $gcd(x,a0)=a1$
- $lcm(x,b0)=b1$
- 求解x的个数，如果不存在输出0
# 思路
- 唯一分解定理+质因数分解
- **质因数分解**：对于任何一个数n，对它质因数分解只需要枚举到 $\sqrt(n)$ 不断试除，如果最后剩余的不是1，那剩余的就是唯一的大于根号n的因子
- 对于一个质因子p，和公约数相关的会限制次数的下界，和公倍数相关的会限制次数的上界
    - 如果a0和a1相同下界就是这个值，如果a0和a1不同次数就只能是a1
    - 如果b0和b1相同上界是这个值，如果b0和b1不同次数就只能是b1
- 题目保证：cnta1<=cnta0，cntb0<=cntb1
- 最后判断即可
# 代码
```cpp
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int v[2020202],prime[2020202],cnt;

void sieve(int lim){
    for(int i=2;i<=lim;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
        }
        for(int j=1;i<=cnt;i++){
            if(prime[j]*i>lim||prime[j]>v[i]) break;
            v[i*prime[j]]=prime[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    sieve(50010);
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++){
        int a0,a1,b0,b1;
        int cnta0,cnta1,cntb0,cntb1;
        cin >> a0 >> a1 >> b0 >> b1;
        long long ans=1;
        for(int j=1;j<=cnt;j++){
            if(prime[j]>b1) break;
            cnta0=cnta1=cntb0=cntb1=0;
            while(a0%prime[j]==0){
                a0/=prime[j];
                cnta0++;
            }
            while(a1%prime[j]==0){
                a1/=prime[j];
                cnta1++;
            }
            while(b0%prime[j]==0){
                b0/=prime[j];
                cntb0++;
            }
            while(b1%prime[j]==0){
                b1/=prime[j];
                cntb1++;
            }
            if(cntb1==0) continue;

            if(cnta1==cnta0&&cntb0==cntb1){
                ans*=cntb0-cnta0+1;
            }else if(cnta1!=cnta0&&cntb1!=cntb0&&cnta1!=cntb1){
                ans=0;
                break;
            }
        }
        if(b1==b0&b1!=a1&&b1!=a0) ans*=2;
        cout << ans << endl;
    }
    return 0;
}
```