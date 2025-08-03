#include<bits/stdc++.h>
#define int ll
using namespace std;
using ll=long long;
ll a[10101];
ll tre1[4*10101];
ll tre2[4*10101];
ll laz_mul[4*10101];
ll laz_add[4*10101];


void build1(int p,int l,int r){
    if(l==r){
        tre1[p]=a[l];
        return ;
    }
    int mid=(r+l)>>1;
    build1(p*2,l,mid);
    build1(p*2+1,mid+1,r);
    tre1[p]=tre1[p*2]+tre1[p*2+1];
}
void build2(int p,int l,int r){
    if(l==r){
        tre2[p]=a[l]*a[l];
        return ;
    }
    int mid=(r+l)>>1;
    build2(p*2,l,mid);
    build2(p*2+1,mid+1,r);
    tre2[p]=tre2[p*2]+tre2[p*2+1];
}
void pushdown(int p,int l,int r){
    laz_mul[p*2]*=laz_mul[p];
    laz_mul[p*2+1]*=laz_mul[p];
    laz_add[p*2]=laz_add[p*2]*laz_mul[p]+laz_add[p];
    laz_add[p*2+1]=laz_add[p*2+1]*laz_mul[p]+laz_add[p];
  
    int mid=(r+l)>>1;
    tre2[p*2]=tre2[p*2]*laz_mul[p]*laz_mul[p]+2*laz_mul[p]*laz_add[p]*tre1[p*2]+laz_add[p]*laz_add[p]*(mid-l+1);
    tre2[p*2+1]=tre2[p*2+1]*laz_mul[p]*laz_mul[p]+2*laz_mul[p]*laz_add[p]*tre1[p*2+1]+laz_add[p]*laz_add[p]*(r-mid);
    
    tre1[p*2]=tre1[p*2]*laz_mul[p]+laz_add[p]*(mid-l+1);
    tre1[p*2+1]=tre1[p*2+1]*laz_mul[p]+laz_add[p]*(r-mid);
    
    laz_add[p]=0;
    laz_mul[p]=1;
}
ll cal1(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tre1[p];
    }
    if(laz_add[p]!=0||laz_mul[p]!=1) pushdown(p,l,r);
    int mid=(l+r)>>1;
    if(x>mid) return cal1(p*2+1,mid+1,r,x,y);
    if(y<=mid) return cal1(p*2,l,mid,x,y);
    return cal1(p*2+1,mid+1,r,x,y)+cal1(p*2,l,mid,x,y);
}

ll cal2(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tre2[p];
    }
    if(laz_add[p]!=0||laz_mul[p]!=1) pushdown(p,l,r);
    int mid=(l+r)>>1;
    if(x>mid) return cal2(p*2+1,mid+1,r,x,y);
    if(y<=mid) return cal2(p*2,l,mid,x,y);
    return cal2(p*2+1,mid+1,r,x,y)+cal2(p*2,l,mid,x,y);
}

void mul(int p,int l,int r,int x,int y,int num){
    if(x<=l&&r<=y){
        tre1[p]*=num;
        tre2[p]*=num*num;
        laz_add[p]*=num;
        laz_mul[p]*=num;
        return ;
    }
    if(laz_add[p]!=0||laz_mul[p]!=1) pushdown(p,l,r);
    int mid=(r+l)>>1;
    if(x<=mid) mul(p*2,l,mid,x,y,num);
    if(y>mid) mul(p*2+1,mid+1,r,x,y,num);
    tre1[p]=tre1[p*2]+tre1[p*2+1];
    tre2[p]=tre2[p*2]+tre2[p*2+1];
}
void add(int p,int l,int r,int x,int y,int num){
    if(x<=l&&r<=y){
        tre2[p]+=num*num*(r-l+1)+2*num*tre1[p];
        tre1[p]+=(r-l+1)*num;
        laz_add[p]+=num;
        return ;
    }
    if(laz_add[p]!=0||laz_mul[p]!=1) pushdown(p,l,r);
    int mid=(r+l)>>1;
    if(x<=mid) add(p*2,l,mid,x,y,num);
    if(y>mid) add(p*2+1,mid+1,r,x,y,num);
    tre1[p]=tre1[p*2]+tre1[p*2+1];
    tre2[p]=tre2[p*2]+tre2[p*2+1];
}

signed main(){
    int n,m;
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=0;i<=4*n;i++){
        laz_add[i]=0;
        laz_mul[i]=1;
    }
    build1(1,1,n);
    build2(1,1,n);
    for(int i=0;i<m;i++){
        int op;
        cin >> op;
        if(op==1){
            int l,r;
            cin >> l >> r;
            cout << cal1(1,1,n,l,r) << endl;
        }else if(op==2){
            int l,r;
            cin >> l >> r;
            cout << cal2(1,1,n,l,r) << endl;
        }else if(op==3){
            int l,r,x;
            cin >> l >> r >> x;
            mul(1,1,n,l,r,x);
        }else{
            int l,r,x;
            cin >> l >> r >> x;
            add(1,1,n,l,r,x);
        }
    }
    return 0;
}