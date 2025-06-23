# A 小红的签到题
## 题意
- 输入一个大于等于三的整数n
- 输出一个长为n的由\"\_\"分为两段的字符串
## 思路
- 直接硬输出即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << "a_";
    for(int i=2;i<n;i++){
        cout << 'a';
    }
    cout << endl;
    return 0;
} 
```
# B 小红的模拟题
## 题意
- 读入一张n\*m的地图，其中有且仅有一个陷阱，输出一条从(1,1)到(n,m)的路径，要求不走陷阱
## 思路
- 由于只有一个陷阱，无非两种情况，路径过陷阱，路径不过陷阱，所以两条无交点路径总有一条能不走陷阱，判断即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

char mp[1010][1010];
int main(){
    int n,m;
    int nx,ny;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mp[i][j];
            if(mp[i][j]=='#'){
                nx=i;ny=j;
            }
        }
    }
    if(nx==1||ny==m){
        for(int i=0;i<n-1;i++) cout << 'S' ;
        for(int i=0;i<m-1;i++) cout << 'D' ;
    }else{
        for(int i=0;i<m-1;i++) cout << 'D' ;
        for(int i=0;i<n-1;i++) cout << 'S' ;        
    }
    return 0;
}
```
# C 小红的方神题
## 题意
- 给定长度n，定义一次操作为将长为n的数组变为长为n-1的数组，新数组中每个元素为$|a_{i}-a_{i+1}|$，能否在n-1次操作后使得仅剩的一个值为n-2
## 思路
- 由于最后为n-2，那么n-2一定是由这几个组合之一操作得来的`{[n,2],[n-1,1][n-2,0]}`，由于`[n,2]`中n是不可能出现的，而`[n-1,1]`的组合再往上推一次操作还是会出现n，所以一定是由`[n-2,0]`得来，观察发现，把`1~n-1`倒序，最后放置n即可完成构造，但至少需要两次才可出现n-2，所以n<=2不可能，剩下直接输出即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n<=2) cout << -1 ;
    else{
        for(int i=n-1;i>=1;i--){
            cout << i <<' ';
        }
        cout << n;
    }
    return 0;
}
```
# D 小红的数学题
## 题意
- 给定正整数k，p+q=k，求是否存在p，q，使得$x^2-px+q=0$
- k~1e12
## 思路
- 错解：带入q=p-k，解方程得$p\geq2\sqrt{k+1}-2$ ，从这个范围枚举到k，验算delta是否大于零，是否是完全平方数，即可
- 误认为是$O(\sqrt{n})$，会T
- 而且k+1开完根后向下取整可能会误判，向上取整可能会漏答案
- **正解：** 由韦达定理，$p=x_{1}+x_{2},q=x_{1}x_{2}$，带入原方程可得$x_{1}x_{2}+x_{1}+x_{2}=k$，进一步化简$(x_{1}+1)(x_{2}+1)=k+1$，又所以只需要枚举其中一个因式，检查是否被整除即可，不妨设$A=x_{2}+1$，由于正整数解，所以$A\geq2$，枚举A($[2,\lfloor   \sqrt{k+1}\rfloor]$ )即可
## 代码
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int k;
    cin >> k;
    //丢精度过不了
    // int p = 2*((int)sqrt(k+1))-2;
    // for(;p<k;p++){
    //     int delt=p*p-4*(k-p);
    //     if(delt<0)continue;
    //     else{
    //         if(sqrt(delt)*sqrt(delt)==delt) cout << p << ' ' << k-p ;
    //         return 0;
    //     }
    // }
    // cout << -1 ;
    int up=sqrt(k+1);
    for(int i=2;i<=up;i++){
        if((k+1)%i==0){
            int p=(i-1)+((k+1)/i-1);
            cout << p << ' ' << k-p <<endl; 
            return 0;
        }
    }
    cout << -1 ;
    return 0;
}
```
# E 小红的ds题
## 题意
- 构造一颗n层二叉树，每层有$a_{i}$个结点
- 先输出根，然后输出每个结点的左儿子和右儿子，没有儿子输出-1
## 思路
- 由于最后只需要输出左右儿子，所以我们并不需要真的维护出这棵树，开两个map分别记录每个点的左右儿子即可
- 不妨设1为根，每层读入后动态开点(全局idx记录每个点的编号)
- 由于只需要看两层之间的关系，每次都只需要记录当前层和上一层，做滚动即可（vector之间可以直接传递，可以直接将一个vector整体赋给另一个vector）
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[2020]={0};
    cin >> n ;
    int sum=1;
    int idx=1;
    vector<int>now;
    vector<int>pst(1,1);
    unordered_map<int,int> L,R;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num ;
        if(i==1) continue;
        sum+=num;
        for(auto j:pst){
            if(num>=2){
                now.push_back(++idx);
                L[j]=idx;
                now.push_back(++idx);
                R[j]=idx;
                num-=2;
            }else if(num>=1){
                now.push_back(++idx);
                L[j]=idx;
                R[j]=-1;
                num--;
            }else{
                L[j]=-1;
                R[j]=-1;
            }
        }
        pst=now;
        now.clear();        
    }
    for(auto i:pst){
        L[i]=-1;R[i]=-1;
    }
    cout << 1 << endl;
    for(int i=1;i<=sum;i++){
        cout << L[i] << ' ' << R[i] << endl;
    }

    return 0;
}
```
# F 小红的小苯题
## 题意
- 构造一个n行m列的矩阵，满足：每一行每一列的异或和，共n+m个，刚好构成长度为n+m的排列，矩阵的每个元素在0\~1e9之间
## 思路
- 对于矩阵$\begin{pmatrix}a&b&c\\d&e&f\end{pmatrix}$ ,这5个数分别为{a^b^c,d^e^f,a^d,b^e,c^f}，而这5个数的异或和恰好又为0，所以得到成立的必要条件：**这个1~n+m的排列异或和为0**
- 由于异或性质中$a \oplus 0=a$，所以我们尽可能多填零来避免影响，尝试如下：
	$\begin{pmatrix}1  &0  &0  &0  &1\oplus6   \\0  &2  &0  &0  &2\oplus7   \\ 0 &0  &3 &4 &? \end{pmatrix}$
- 从一开始按照排列顺序先填对角线，来满足列的异或和，列的填不下了就往最后一行剩余列填
- 最后要留一列来调整行的异或和，我们希望?处列和是5
- 调整最后一列的每一行，填充排列剩下的数字，同样地，我们希望?处行和是8(n+m)
- 因此用希望的列和去和这一列的每一个元素去异或，即可得到?处应当填的元素x，再用x去和这一行中的每个元素做异或，检查结果是不是n+m即可
- 这时我们发现，上面两次异或的式子刚好就是1~n+m-1的异或和等于n+m
- 变形可得充分条件：**这个1~n+m的排列异或和为0**
- 综上，充要条件有了，构造方法有了，实现即可
## 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,f=0;
    cin >> n >> m ;
    if(n>m){
        swap(n,m);
        f=1;
    }
    vector<vector<int>> g(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        g[i][i]=i;
    }
    for(int i=n+1;i<m;i++){
        g[n][i]=i;
    }
    int lie_sum=m;
    for(int i=1;i<n;i++){
        g[i][m]=i^(i+m);
        lie_sum^=g[i][m];
    }
    g[n][m]=lie_sum;
    for(int i=1;i<m;i++){
        lie_sum^=g[n][i];
    }
    if(lie_sum!=n+m) cout << -1 << endl;
    else{
        if(f==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout << g[i][j] << " \n"[j==m] ;
                }
            }
        }else{
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    cout << g[j][i] << " \n"[j==n] ;
                }
            }
        }

    }

    return 0;
}
```



