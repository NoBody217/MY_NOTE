#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct ty{
    int mx,mn,num;
}tree[4010101];
int a[4010101];

void build(int p,int l,int r){
    if(l==r){
        tree[p].mx=a[l];
        tree[p].mn=a[l];
        tree[p].num=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].mx=max(tree[p*2].mx,tree[p*2+1].mx);
    tree[p].mn=min(tree[p*2].mn,tree[p*2+1].mn);
    tree[p].num=tree[p*2].num+tree[p*2+1].num;
}

void del(int p,int l,int r,int x){
    if(l==r){
        tree[p].mx=-0x3f3f3f3f;
        tree[p].mn=0x3f3f3f3f;
        tree[p].num=0;
        return ;
    }
    int mid=(l+r)>>1;
    if(tree[p*2].num<x) del(p*2+1,mid+1,r,x-tree[p*2].num);
    else del(p*2,l,mid,x);
    tree[p].mx=max(tree[p*2].mx,tree[p*2+1].mx);
    tree[p].mn=min(tree[p*2].mn,tree[p*2+1].mn);
    tree[p].num=tree[p*2].num+tree[p*2+1].num;
}

ty cal(int p,int l,int r,int x,int y){
    // cout << l << ' ' << r << ' ' << tree[p].num << endl;
    if(x<=1&&y>=tree[p].num){
        return tree[p];
    }
    int mid=(l+r)>>1;
    if(tree[p*2].num>=y) return cal(p*2,l,mid,x,y);
    if(tree[p*2].num<x) return cal(p*2+1,mid+1,r,x-tree[p*2].num,y-tree[p*2].num);
    ty t1,t2;
    t1=cal(p*2,l,mid,x,tree[p*2].num);
    t2=cal(p*2+1,mid+1,r,1,y-tree[p*2].num);
    t1.mn=min(t1.mn,t2.mn);
    t1.mx=max(t1.mx,t2.mx);
    return t1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);

    for(int i=0;i<m;i++){
        int op;
        cin >> op;
        if(op==1){
            int k;
            cin >> k;
            del(1,1,n,k);
        }else{
            int l,r;
            cin >> l >> r;
            ty ans=cal(1,1,n,l,r);
            cout << ans.mn << ' ' << ans.mx << endl;
        }
    }
    return 0;
}