#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

struct Q{
    int l,r,id,ans;
}q[2020202];
int a[2020202],tree[2020202];
int last1[2020202],last2[2020202];
int n,c,m;

int lowbit(int x){ return x&(-x); }
void add(int x,int val){
    while(x<=n){
        tree[x]+=val;
        x+=lowbit(x);
    }
}
int sum(int x){
    int s=0;
    while(x>0){
        s+=tree[x];
        x-=lowbit(x);
    }
    return s;
}


bool cmp1(Q x,Q y){
    return x.r<y.r;
}

bool cmp2(Q x,Q y){
    return x.id<y.id;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> c >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> q[i].l >> q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp1);
    map<int,int> mp;
    int pos=1;
    for(int i=1;i<=n;i++){
        mp[a[i]]++;
        if(mp[a[i]]>=2){
            add(last2[a[i]]+1,1);
            add(last1[a[i]]+1,-1);
        }
        last2[a[i]]=last1[a[i]];
        last1[a[i]]=i;
        while(pos<=m&&q[pos].r==i){
            q[pos].ans=sum(q[pos].l);
            pos++;
        }
    }
    sort(q+1,q+1+m,cmp2);
    for(int i=1;i<=m;i++){
        cout << q[i].ans <<endl;
    }
    return 0;
}