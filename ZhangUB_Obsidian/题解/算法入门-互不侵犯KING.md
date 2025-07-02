#状压dp
# 题意
- 有一个N\*N(N<10)的棋盘，其中需要放置K个国王，国王会攻击以他为中心的九宫格范围内的棋子，要是所有国王互不攻击，总共有多少种方案
# 思路
- 如果按顺序从上到下，从左到右，每次放置新的国王的时候都需要考虑它左边和上侧的国王，状态过于复杂难以描述
- 由于N不大可以考虑一行一行放置，这样每一次只需要考虑上一行的状态即可
- 使用01串描述每一行的状态，**提前预处理出来每一行合法的情况，避免动态规划过程中反复枚举**
- 对于不打架这件事
    - 行内：左右不能相邻，如果用a来表示这一行的状态，那就要保证$(a\&(a<<1))=0$
    - 当前行和上一行：对于上一行的一个棋子，他的正下方，左下，右下不能有棋子，即保证$(a\&(b<<1))=0$且$(a\&(b>>1))=0$且$(a\&b)=0$
- 对于动态规划，我们首先需要描述行，其次需要知道已经摆了多少个棋子，最后要知道状态，所以用三个维度来描述状态
    - $dp[i][j][k]$表示第i行，一共放置了j个棋子，放置状态为k
    - $dp[i][j][k]+=dp[i-1][j-num[k]][p] (p为与k不冲突状态)$
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

int calc(int x){
    int ans=0;
    while(x){
        if(x&1)ans++;
        x>>=1;
    }
    return ans;
}
long long dp[10][120][120];
vector<int> st;
vector<int> num;
int main(){
    int n,k;
    cin >> n >> k;
    //枚举可能的状态
    for(int i=0;i<(1<<n);i++){
        if(i&(i<<1))continue;
        st.push_back(i);
        num.push_back(calc(i));
    }

    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int cur=0;cur<st.size();cur++){
                if(num[cur]>j) continue;
                for(int lst=0;lst<st.size();lst++){
                    if(num[lst]+num[cur]>j) continue;
                    if((st[cur]&st[lst])||(st[cur]&(st[lst]<<1))||(st[cur]&(st[lst]>>1))) continue;
                    dp[i][j][cur]+=dp[i-1][j-num[cur]][lst];
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<st.size();i++){
        ans+=dp[n][k][i];
    }
    cout << ans << endl;
    return 0;
}
```