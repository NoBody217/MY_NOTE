#01背包 #多次dp
# 题意
- 有k个物品，每个物品有体积，求空间为1\~m，不带第1\~k件的方案数
# 思路
- 无法考虑枚举不带某一个物品，对剩下的物品01背包，复杂度直接爆炸
- 反向思考，可以求解k个物品装满m空间的01背包(每个物品用一次，恰好装满指定体积)，然后再减去必须取某一个物品装满m空间的方案数，就得到去掉某一个物品装满m空间的方案数
- 设$g[i]$表示去掉某一个物品p背包体积为i的方案数，$f[i]$为体积为i的01背包方案数，那么$g[i-v[p]]$就是必须选p体积为i的方案数
- 因此，状态方程可以表示为$g[i]=f[i]-g[i-v[p]]$
# 代码
```cpp
#include<bits/stdc++.h>
const int N = 2330;
using namespace std;

int f[N],g[N],a[N];
int main(){
    int n,m;
    while(cin >> n >> m){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        f[0]=1;
        for(int i=0;i<n;i++){
            for(int j=m;j>=0;j--){
                if(j-a[i]>=0)
                    f[j]+=f[j-a[i]]%10;
            }
        }

        for(int i=0;i<n;i++){//不带a[i]
            for(int j=0;j<=m;j++){
                if(j<a[i]) g[j]=f[j];
                else g[j]=(f[j]%10-g[j-a[i]]%10+10)%10;
            }
            for(int j=1;j<=m;j++){
                cout << g[j]%10;
            }
            cout << endl;
        }
        
    }
    return 0;
}
```