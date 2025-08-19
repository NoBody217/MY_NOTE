#dp #线段树
- dp场，但没看出来是dp



# E
## 题意
- 给定一个长为n的序列，你可以进行若干次操作：将一个区间整体+1
- 给定m表示最终区间可以有最多m种不同的数字，求解达到要求的最少操作次数
- n<=400,m<=2,a_i<=100
## 思路
- 赛时m=1和m=2都当贪心做了，假了
    - 对于m=1，全体元素变为最大值一定是最优解，直接统计每个元素到最大值的差距，然后差分记录正数即可
    - 对于m=2，枚举第二个元素，序列中比第二个元素大的就变为最大值，否则变为最小值
        - 这个假的原因是，每一个元素变成离它最近的目标值并不一定是最优的，如序列:2,1,5,1
- 每个元素到达的最终状态是不确定的，用动态规划求出所有状态取最小才能找到最优解
    - 对于m=1，同上
    - 对于m=2，枚举最终的两个值，枚举范围的上界不是100，300是比较极限的情况
    - 然后对于每次确定的两个目标值，进行dp
        - $dp[i][0]$ 表示第i个元素最终变成第1个数u，需要的最少操作数
        - $dp[i][1]$ 表示第i个元素最终变成第2个数v，需要的最少操作数
        - 转移方程 $dp[i][0]=min(dp[i-1][0]+max(0,(u-a[i])-(u-a[i-1])),dp[i-1][1]+max(0,(u-a[i])-(v-a[i-1])))$ 剩余的几个类似
    - 最终维护全局最小答案即可
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
const int lim=300;
int dp[450][2];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n+10,0);
        int mn=200,mx=-1;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            mn=min(a[i],mn);
            mx=max(a[i],mx);
        }
        if(m==2){
            int ans=0x3f3f3f3f;
            for(int u=mn;u<=lim;u++){
                for(int v=u;v<=lim;v++){
                    memset(dp,0x3f,sizeof(dp));
                    dp[1][0]=(u-a[1]>=0?u-a[1]:0x3f3f3f3f);
                    dp[1][1]=(v-a[1]>=0?v-a[1]:0x3f3f3f3f);
                    for(int i=2;i<=n;i++){
                        if(a[i]<=u){
                            dp[i][0]=min(dp[i-1][0]+max(0,(u-a[i])-(u-a[i-1])),dp[i-1][1]+max(0,(u-a[i])-(v-a[i-1])));
                        }
                        if(a[i]<=v){
                            dp[i][1]=min(dp[i-1][0]+max(0,(v-a[i])-(u-a[i-1])),dp[i-1][1]+max(0,(v-a[i])-(v-a[i-1])));
                        }
                    }
                    
                    ans=min(ans,min(dp[n][0],dp[n][1]));
//                     cout << u << ' ' << v << ' ' << ans << endl;
                }
            }
            cout << ans << endl;            
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                a[i]=mx-a[i];
            }
            for(int i=1;i<=n;i++){
                ans+=max(0,a[i]-a[i-1]);
            }
            cout << ans << endl;
        }

    }
    return 0;
}
```

# F
## 题意
- 对于长为n的序列，分割成三段，使得在三段中都出现的元素个数最多
## 思路
- 对于一个在第一部分出现的元素，如果希望这个元素最终对答案产生贡献，第二部分和第三部分的分界点一定得在这个元素下一次出现的位置和最后一次出现的位置之间
- 也就是，在第一部分有若干元素后，后续会有若干区间，而答案就是区间覆盖次数最多的地方
- 问题变为，区间覆盖+单点最大值——用线段树维护
- 首先，给每个元素记录最后一次出现位置lst和下一次出现的位置nxt(nxt需要动态维护和修改)
- 然后给第一部分开一个桶，记录哪些元素出现过
- 同时，开一个线段树维护区间最大值和最大值的位置
- 枚举第一部分的尾部的位置，枚举的过程判断新加入的元素是否已经出现过
    - 如果没有出现过，并且这个元素有nxt且nxt!=lst，就给\[nxt,lst-1] 这个区间+1(**-1的原因是因为线段树维护的最大位置实际上是第二个部分的尾部的位置，而lst需要处于最后一个区间，所以可取位置是\[nxt,lst-1]**)
    - 如果出现过，就需要修改上一次统计的贡献，具体来说，当前出现位置到当前的nxt-1不再产生贡献，所以需要给\[i,nxt-1]这个区间-1
- 最后，ans等于0的情况，任意合法l,r都是合理的，记得赋合法初值
## 代码
```cpp
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

unordered_map<int,queue<int>> nxt;
int lst[1010101];
int cnt[1010101];

struct tp{
    int mx,pos,laz;
}t[606060];

void pushdown(int p){
    t[p*2].laz+=t[p].laz;
    t[p*2].mx+=t[p].laz;
    t[p*2+1].laz+=t[p].laz;
    t[p*2+1].mx+=t[p].laz;
    t[p].laz=0;
}

void pushup(int p){
    if(t[p*2].mx>=t[p*2+1].mx){
        t[p].mx=t[p*2].mx;
        t[p].pos=t[p*2].pos;
    }else{
        t[p].mx=t[p*2+1].mx;
        t[p].pos=t[p*2+1].pos;        
    }
}
void build(int p,int l,int r){
    t[p].mx=0;
    if(l==r){
        t[p].laz=0;
        t[p].pos=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}



void deal(int p,int l,int r,int x,int y,int op){
    if(x<=l&&r<=y){
        t[p].laz+=op;
        t[p].mx+=op;
        return ;
    }
    if(t[p].laz!=0) pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid) deal(p*2,l,mid,x,y,op);
    if(y>mid) deal(p*2+1,mid+1,r,x,y,op);
    pushup(p);
}

tp cal(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        // cout << p << ' ' << l << ' ' << r << ' ' << x<< ' ' << y<< ' ' << t[p].mx << ' ' << t[p].pos<< endl;
        return t[p];
    }
    if(t[p].laz!=0) pushdown(p);
    int mid=(l+r)>>1;
    if(x>mid) return cal(p*2+1,mid+1,r,x,y);
    if(y<=mid) return cal(p*2,l,mid,x,y);
    tp ls=cal(p*2,l,mid,x,y);
    tp rs=cal(p*2+1,mid+1,r,x,y);
    return ls.mx>rs.mx?ls:rs;
}

void solve(){
    nxt.clear();
    for(int i=0;i<=1010101;i++){ lst[i]=0; cnt[i]=0; }

    int n;
    cin >> n ;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        nxt[a[i]].push(i);
        lst[a[i]]=i;
    }
    build(1,1,n);
    int ans=0,rr,ll;
    for(int i=1;i<=n-2;i++){//i是第一个区间结尾
        nxt[a[i]].pop();
        if(cnt[a[i]]){
            if(!nxt[a[i]].empty())
                deal(1,1,n,i,nxt[a[i]].front()-1,-1);
        }else{
            cnt[a[i]]++;
            if(!nxt[a[i]].empty()&&nxt[a[i]].front()!=lst[a[i]])
                deal(1,1,n,nxt[a[i]].front(),lst[a[i]]-1,1);
        }
        tp tmp=cal(1,1,n,i+1,n-1);//找第二个区间结尾
        // cout << i+1 << ' ' << tmp.mx << ' ' << tmp.pos << endl;
        if(tmp.mx>ans){
            ans=tmp.mx;
            ll=i+1;rr=tmp.pos+1;
        }
    }
    cout << ans << endl;
    cout << ll << ' ' << rr << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
```