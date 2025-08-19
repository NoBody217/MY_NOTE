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