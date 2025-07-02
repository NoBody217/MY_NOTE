#动态规划 #概率
# 题意
- 买彩票，3元一张，中1,2,3,4元的概率相等
- 买n张，求不亏的概率
- 输出要求：最简分数，如果概率为0就输出"0/1"，概率为1就输出"1/1"
# 思路
- 类似昨天弹球的问题
- 状态转移可以靠钱勾连
- $dp[i][j]$表示买了i张彩票赚j元的可能
- $dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]$
- 最后求一个GCD就行，注意只要买了就会亏，所以概率为1只有可能是一张不买
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

long long dp[40][200];
int main(){
    int n;
    cin >> n;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=4*n;j++){
            dp[i][j]=(j>=1?dp[i-1][j-1]:0)+(j>=2?dp[i-1][j-2]:0)+(j>=3?dp[i-1][j-3]:0)+(j>=4?dp[i-1][j-4]:0);
        }
    }
    long long bas=0,sum=0;
    for(int i=0;i<=4*n;i++){
        bas+=dp[n][i];
        if(i>=3*n)sum+=dp[n][i];
    }
    long long deal=gcd(bas,sum);
    if(n==0) cout << "1/1" << endl;
    else if(deal==0) cout << "0/1" << endl;
    else cout << sum/deal << '/' << bas/deal <<endl;
    return 0;
}
```