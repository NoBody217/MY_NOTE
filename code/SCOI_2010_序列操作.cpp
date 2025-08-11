#include<bits/stdc++.h>
using namespace std;
const int N=101010;

int a[N];
struct t{
    int laz;
    int sum[2],max[2],left[2],right[2];
}tree[4*N];

void pushup(int p,int l,int r){
    int mid=(l+r)>>1;
    for(int i=0;i<2;i++){
        tree[p].sum[i]=tree[p*2].sum[i]+tree[p*2+1].sum[i];
        tree[p].max[i]=max(tree[p*2].max[i],max(tree[p*2+1].max[i],tree[p*2].right[i]+tree[p*2+1].left[i]));
        if(tree[p*2].left[i]==mid-l+1) tree[p].left[i]=tree[p*2].left[i]+tree[p*2+1].left[i];
        else tree[p].left[i]=tree[p*2].left[i];
        if(tree[p*2+1].right[i]==r-mid) tree[p].right[i]=tree[p*2+1].right[i]+tree[p*2].right[i];
        else tree[p].right[i]=tree[p*2+1].right[i];
    }
}

void build(int p,int l,int r){
    tree[p].laz=-1;
    if(l==r){
        tree[p].sum[a[l]]=tree[p].max[a[l]]=tree[p].left[a[l]]=tree[p].right[a[l]]=1;
        return ;
    }
    int mid=(r+l)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p,l,r);
}

void mswap(int p){
    swap(tree[p].left[0],tree[p].left[1]);
    swap(tree[p].right[0],tree[p].right[1]);
    swap(tree[p].max[0],tree[p].max[1]);
    swap(tree[p].sum[0],tree[p].sum[1]);
}

void pushdown(int p,int l,int r){
    if(tree[p].laz==2){

        if(tree[p*2].laz==-1) tree[p*2].laz=2;
        else if(tree[p*2].laz==2) tree[p*2].laz=-1;
        else tree[p*2].laz^=1;

        if(tree[p*2+1].laz==-1) tree[p*2+1].laz=2;
        else if(tree[p*2+1].laz==2) tree[p*2+1].laz=-1;
        else tree[p*2+1].laz^=1;        
        mswap(p*2);
        mswap(p*2+1);
    }else{
        int op=tree[p].laz;
        int mid=(r+l)>>1;
        tree[p*2].laz=op;
        tree[p*2].sum[op]=tree[p*2].left[op]=tree[p*2].right[op]=tree[p*2].max[op]=mid-l+1;
        tree[p*2].sum[op^1]=tree[p*2].left[op^1]=tree[p*2].right[op^1]=tree[p*2].max[op^1]=0;       
        tree[p*2+1].laz=op;
        tree[p*2+1].sum[op]=tree[p*2+1].left[op]=tree[p*2+1].right[op]=tree[p*2+1].max[op]=r-mid;
        tree[p*2+1].sum[op^1]=tree[p*2+1].left[op^1]=tree[p*2+1].right[op^1]=tree[p*2+1].max[op^1]=0;
    }
    tree[p].laz=-1;
}

void change(int p,int l,int r,int x,int y,int op){
    if(x<=l&&r<=y){
        tree[p].laz=op;
        tree[p].sum[op]=tree[p].left[op]=tree[p].right[op]=tree[p].max[op]=r-l+1;
        tree[p].sum[op^1]=tree[p].left[op^1]=tree[p].right[op^1]=tree[p].max[op^1]=0;
        return ;
    }
    if(tree[p].laz!=-1) pushdown(p,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) change(p*2,l,mid,x,y,op);
    if(y>mid) change(p*2+1,mid+1,r,x,y,op);
    pushup(p,l,r);
}

void reverse(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        mswap(p);
        if(tree[p].laz==-1) tree[p].laz=2;
        else if(tree[p].laz==2) tree[p].laz=-1;
        else tree[p].laz^=1;
        return ;
    }
    if(tree[p].laz!=-1) pushdown(p,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) reverse(p*2,l,mid,x,y);
    if(y>mid) reverse(p*2+1,mid+1,r,x,y);
    pushup(p,l,r);
}

int find1(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tree[p].sum[1];
    }
    if(tree[p].laz!=-1) pushdown(p,l,r);
    int mid=(r+l)>>1;
    if(x>mid) return find1(p*2+1,mid+1,r,x,y);
    if(y<=mid) return find1(p*2,l,mid,x,y);
    return find1(p*2+1,mid+1,r,x,y)+find1(p*2,l,mid,x,y);
}

t find2(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tree[p];
    }
    if(tree[p].laz!=-1) pushdown(p,l,r);
    int mid=(r+l)>>1;
    if(x>mid) return find2(p*2+1,mid+1,r,x,y);
    if(y<=mid) return find2(p*2,l,mid,x,y);
    t t1=find2(p*2,l,mid,x,y);
    t t2=find2(p*2+1,mid+1,r,x,y);
    t1.max[1] = max(max(t1.max[1], t2.max[1]), t1.right[1]+t2.left[1]);
    if (t1.left[1] == mid-l+1) t1.left[1] += t2.left[1];
    if(t2.right[1] == r-(mid+1)+1) t1.right[1] = t1.right[1]+t2.right[1];
    else t1.right[1] = t2.right[1];
    return t1;
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    for(int i=0;i<m;i++){
        int op,a,b;
        cin >> op >> a >> b;
        a++,b++;
        if(op==0){
            change(1,1,n,a,b,0);
        }else if(op==1){
            change(1,1,n,a,b,1);
        }else if(op==2){
            reverse(1,1,n,a,b);
        }else if(op==3){
            cout << find1(1,1,n,a,b) << endl;
        }else{
            cout << find2(1,1,n,a,b).max[1] << endl;
        }
    }

    return 0;
}