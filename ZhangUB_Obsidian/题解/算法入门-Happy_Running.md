# 题意
- 长为x的跑道上有A，B两个打卡点，必须先在A打卡再在B打卡
- 请问完成两次打卡后跑步距离超过k的概率
# 思路
- 用图形算概率，横轴为A纵轴为B，占比就是概率
- 如果k<x，那么只要B<=A||(B>A&&B\>k)就可以
- 如果k>x，那么B>=k-x&&B<=A
- 如果k>2x，寄
- 如果k=x，当且仅当B<=A
# 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k,x;
    scanf("%d%d",&k,&x);
    if(k>2*x)
        printf("0.00\n");
    else if(k>x)
        printf("%0.2lf\n",1.0*(2*x-k)*(2*x-k)/(2.0*x*x));
    else if(k==x)
        printf("0.50\n");
    else 
        printf("%0.2lf\n",1.0-(1.0*k*k/2.0)/x/x);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
```