#数学 #整数分块 #思维
# 题意
- 定义F(n)为n的约数和，G(n)为F(1)+F(2)+...+F(n-1)+F(n)
- 给定n，求(G(n))
# 思路
- 依然考虑贡献，对于一个因子i，包含i的数的个数是n/i个，产生的贡献是i\*\[n/i]，对于G(n)转换成求 $\sum_{i=1}^{n}i*[\frac{n}{i}]$
- 对于 $[\frac{n}{i}]$ 分块，发现在i超过根号n后一段定长的区间内 $[\frac{n}{i}]$ 的值是固定的，但i是公差为1的等差数列
- 对于每一个块，分界总是 $n/[\frac{n}{i}]$ 
- 对每个块计算即可
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

long long g(long long n){
    long long ans=0;
    for(int i=1;i<=n;){
        long long s=n/i;
        long long r=n/s;
        ans+=s*(i+r)*(r-i+1)/2;
        i=r+1;
    }
    return ans;
}

int main(){
    long long n;
    cin >> n;
    cout << g(g(n));
    return 0;
}
```

