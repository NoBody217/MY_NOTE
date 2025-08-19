#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct ty{
    int typ,pos,num;
}a[401010];
vector<int> G[101010];

int tim;
int t[404040];
int l[404040],r[404040];

void dfs(int x,int fa){
    l[x]=++tim;
    for(auto i:G[x]){
        if(i==fa) continue;
        dfs(i,x);
    }
    r[x]=tim;
}

void build(int p,int l,int r){
    if(l==r){
        t[p]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}

void pushdown(int p){
    t[p*2]+=t[p];
    t[p*2+1]+=t[p];
    t[p]=0;
    // for(int i=1;i<=30;i++){
    //     cout << t[i] << ' ';
    // }
    // cout << endl;
}

void change(int p,int l,int r,int x){
    if(l==r){
        t[p]=0;
        return ;
    }
    if(t[p]!=0) pushdown(p); 
    int mid=(l+r)>>1;
    if(x>mid) change(p*2+1,mid+1,r,x);
    else change(p*2,l,mid,x);
}

void add(int p,int l,int r,int x,int y,int num){
    if(x<=l&&r<=y){
        t[p]+=num;
        return ;
    }
    if(t[p]!=0) pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid) add(p*2,l,mid,x,y,num);
    if(y>mid) add(p*2+1,mid+1,r,x,y,num);
}

int cal(int p,int l,int r,int x){
    // cout << p << ' ' << l << ' ' << r << ' ' << x << endl;
    if(l==r) return t[p];
    if(t[p]!=0) pushdown(p); 
    int mid=(l+r)>>1;
    if(x>mid) return cal(p*2+1,mid+1,r,x);
    else return cal(p*2,l,mid,x);    
}

int main(){
    int m,n=1;
    cin >> m;
    for(int i=1;i<=m;i++){
        int op;
        cin >> op;
        if(op==1){
            int tmp;
            cin >> tmp;
            G[tmp].push_back(n);
            a[i]={1,n,0};
            n++;
        }else if(op==2){
            int tmp,num;
            cin >> tmp >> num;
            a[i]={2,tmp,num};
        }else if(op==3){
            int tmp;
            cin >> tmp;
            a[i]={3,tmp,0};
        }
    }
    dfs(0,-1);
    build(1,1,n);

    for(int i=1;i<=m;i++){
        if(a[i].typ==1){
            change(1,1,n,l[a[i].pos]);
        }else if(a[i].typ==2){
            add(1,1,n,l[a[i].pos],r[a[i].pos],a[i].num);

        }else{
            cout << cal(1,1,n,l[a[i].pos]) << endl;
        }
    }

    return 0;
}