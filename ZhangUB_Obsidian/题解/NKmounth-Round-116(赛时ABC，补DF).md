# [比赛链接](https://ac.nowcoder.com/acm/contest/109080#question)
# A 简单游戏(语法)
## 题意
- 给定三个数，和一个序号，问序号位置的数是不是最大的
## 思路
- 遍历整个数组，找不到比他大的就Y，找不到就N
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]={0},idx;
    for(int i=1;i<=3;i++){
        cin >> a[i];
    }
    cin >> idx;
	for(int i=1;i<3;i++){
		if(a[i]>a[idx]){
			cout << "No" << endl;
			return 0;
		} 
	}
    cout << "Yes" << endl;
    return 0;
}
```
# B 邪神的战斗力(语法，小学奥数)
## 题意
- 给定n个人，每个人有自己的权值，每次询问一个人，他会回答其余人的权值和，给定每个人的回答，求每个人的权值
## 思路
- 将所有人的回答加和刚好是(n-1)\*sum，因此可以得到所所有人的和，对于每个人，sum减去他的回答就是他的权值
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

int a[202020];
int main(){
    int n;
    long long sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sum/=(n-1);
    for(int i=1;i<=n;i++){
        cout << sum-a[i] << ' ' ;
    }
    return 0;
}
```
# C,F poi的新加法(Easy Version&&Hard Version)(位运算，剪枝)
## 题意
- 定义一种新的加法$f(x,y)=x+y-(x \oplus y)$ 
- T组测试，每组测试n个元素，q次询问，n，q均为1e6量级
- 每次询问需要输出\[l,r]的区间和
## 思路
- Easy Version直接暴力就能过，Hard Version如果暴力复杂度是$O(n*q)$，TLE
- 二进制性质：$x+y=2*(x \& y)+(x \oplus y)$
- 由这个性质可以发现，这个新加法的逆运算是找不到的，因为按位与是没有逆运算的
- 所以**前缀和**是走不通的
- 由这个式子可以看出每进行一次操作$f(x,y)=(x \& y) << 1$一定会给最后一位加上一个0，由于元素范围小于2\^60，所以进行超过60次操作后，和式一定变为0
- 而在60次以内时，可以直接暴力，复杂度为$O(60*q)$
## 代码
```cpp
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

vector<ull> v(1010101);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t ;
    while(t--){
        int n, q;
        cin >> n >> q ;
        for(int i=0;i<n;i++){
            cin >> v[i] ;
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r ;
            l--;r--;
            if(r-l+1>61){
                cout << 0 << '\n' ;
                continue;
            }
            ull ans=v[l];
            for(int j=l+1;j<=r;j++){
                ans=(ans&v[j])<<1;
            }
            cout << ans << '\n' ;
        }
    }
    return 0;
}
```
# DF poi的消消乐(思维，贪心)
## 题意
- n个石头，序号从0开始，最多两种颜色，石头可以压缩，求最少可以压缩成几块
- 输入：每次输入长度和整个序列，用不同字母代表不同颜色
- 压缩规则如下：对于$i \leq j < k \leq l$ 且 $j+1=k$ 如果 $color_{i*j}=color_{k*l}$ 则可以讲这两块石子合并
## 思路
- 由于最多有两种颜色，我们使用a，b表示某种颜色的单块石头，A，B表示某种颜色的连续一串石头
- 石头的排列情况一共有如下几种
	- A
	- AB
	- ABA
	- ABAB
- 对于复杂的i,j,k,l关系，应当先从0开始尝试，不妨取i=j=0,此时k=1
	- 那么i\*j=0，k\*l可以选取到整个序列中任何一个石头，意味着，所有和第一个石头颜色一样的石头可以删除
		- 情况一的答案一定是1
		- 情况二可以变为aB，那么对于aB是否可以继续优化？将i=j=1,k=2,这样发现从第四个往后的b也可以全被消除，则情况二的最优解是abbb，不过b有可能不够三个所以情况二最终答案是**1+min(3,count(b))**
		- 情况三变为aBa后发现更优的解决逻辑，把第一个a合并到后面，最终可以变为ba，答案是2
		- 情况四和情况三没区别
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
/**
 * 共计三种情况
 * 全都是一种字母：压缩为只有一个
 * 前半段是第一种字母，后半段是第二种字母：一定可以压缩为前半段只剩1个，后半段最多3个
 * 超过两段：ABAB……，从第二个A之后的所有A都可以被压缩掉
 * 前面的A可以压缩至第一个B后面的唯一一个A，变为BAB，A后面的B可以全压缩掉，最后变为BA
 * 
 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n ;
        string s;
        cin >> s ;
        int a=count(s.begin(),s.end(),s[0]);//count函数统计a个数
        int b=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[0]) b++;//统计第一段a个数
            else break;
        }
        if(a==b) cout << 1+min(n-a,3) << endl ;//前两种情况
        else cout << 2 << endl;

    }
    return 0;
}
```
