#状压dp
# 题意
- n行m列矩形，用1\*2的矩形块填充，有多少种填充方案
# 思路
- 依然是棋盘放置一类的问题，考虑一行一行放
- 对于每一行，上一行竖着放的地方一定放不了，上一行横着放的地方可以竖着放也可以横着放，行内不可能的是把一个横着的拆开，两行间不可能的是，上一行竖着，这一行还放东西
- 设计状态：横着放记为0，竖着放记为1，竖着放的下一行记为0
    - 这样子新st和旧st做与就可以排除行间冲突
    - 而对于行内，除了上一行是1的位置任意枚举，但是连续的0必须是偶数个，将新st和旧st做或运算，排除原来的1带来的影响，检查剩下的0是不是偶数个连续即可
# 代码
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 还是一行一行的放，横着放记为0,竖着放记为1
 * 如果上一行是1,下一行就是0,如果上一行是0，下一行0必须偶数个
 * 枚举新一行的st，检查是否符合上一行规则
 * 两行的与必须是0,否则说明有两格1
 * 两行的或中0必须是偶数个，用或来排除上行1下行0的情况
 * 011101100
 * 100010011
 * 1???1
 * 
 * dp[i][st]表示第i行状态为st的情况
 * 
 */



int n,m;
int dp[15][1<<15];
int judge(int st){
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(st&1){
            if(cnt%2)return -1;
            cnt=0;
        }else
            cnt++;
        st>>=1;
    }
    return cnt%2?-1:1;
}

signed main(){
    while(1){
        cin >> m >> n;
        if(m==n&&n==0) break;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int cur=0;cur<=(1<<m)-1;cur++){
                for(int lst=0;lst<=(1<<m)-1;lst++){
                    if(cur&lst) continue;
                    if(judge(cur|lst)==-1)continue;
                    dp[i][cur]+=dp[i-1][lst];
                }
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}
```