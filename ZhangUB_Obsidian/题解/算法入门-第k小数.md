#模拟
#  题意
- 给定若干组数组，每组数组给出长度n和询问k
- 输出第k大的数
# 思路
- 水题，直接硬模拟+排序即可
- 注意输入量很大，需要使用快读
```cpp
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
```
# 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=read();
    while(t--){
        int n=read();
        int k=read();
        vector<int> a(n+10);
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        sort(a.begin()+1,a.begin()+n+1);
        // for(int i=1;i<=n;i++) cout << a[i] << ' ';
        // cout << '\n';
        cout << a[k] << endl;
    }
    

    return 0;
}
```