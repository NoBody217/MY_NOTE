#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct L{
    long long x,y1,y2;
    bool flg;
}line[N];
int cnt;
long long seg[N];

long long tree[N*4];
int lazy[N*4];

unordered_map<long long,int> mp;

void build(int p,int l,int r){
    if(l==r){
        tree[p]=0;
        lazy[p]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}

void update(int p,int l,int r){
    if(lazy[p]>0) tree[p]=seg[r+1]-seg[l];
    else if(l!=r) tree[p]=tree[p*2]+tree[p*2+1];
    else tree[p]=0;
}


void deal(int p,int l,int r,int x,int y,bool op){
    // cout << p <<' '<< l << ' ' << r << ' ' << x << ' ' << y <<endl;
    if(x<=l&&r<=y){
        lazy[p]+=(op?1:-1);
        update(p,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) deal(p*2,l,mid,x,y,op);
    if(y>mid) deal(p*2+1,mid+1,r,x,y,op);
    update(p,l,r);
}

bool cmp(L a,L b){
    return a.x<b.x;
}


int main(){
    int tst=1;
    int n;
    scanf("%d",&n);
    long long x1,x2,y1,y2;
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        line[++cnt]={x1,y1,y2,1};
        seg[cnt]=y1;
        line[++cnt]={x2,y1,y2,0};
        seg[cnt]=y2;
    }
    sort(line,line+1+cnt,cmp);
    sort(seg,seg+1+cnt);
    int m=unique(seg+1,seg+cnt+1)-(seg+1);
    for(int i=1;i<=m;i++){
        mp[seg[i]]=i;
    }
    m--;
    build(1,1,m);
    long long ans=0;
    for(int i=1;i<cnt;i++){
        int L=mp[line[i].y1];
        int R=mp[line[i].y2]-1;
        deal(1,1,m,L,R,line[i].flg);
        ans+=tree[1]*(line[i+1].x-line[i].x);
    }
    printf("%lld\n",ans);
    return 0;
}