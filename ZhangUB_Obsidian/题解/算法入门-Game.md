# 题意
- 对于一个数n，两个人每次可以把它拆分成两个因数，没得拆的人输，给定n，判断胜负情况
# 思路
- 对任何一个数，最终一定会被拆成它的质因数分解形式，然后无法继续拆解
- 而中途的拆法并不影响结果
- 每次拆会使得总数+1，总共能拆因子个数-1次
- 如果质因数分解有奇数个因子，先手必败
- 反之后手必败
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

int prime[100000];
int vis[100000];
int cnt=0;
void sieve(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>lim||vis[i*prime[j]]) break;
            vis[i*prime[j]]=vis[i]+vis[prime[j]];
        }
    }
}
int main(){
    int n;
    cin >> n;
    sieve(n);
    cout << (vis[n]%2?"Nancy":"Johnson") << endl;
}
```