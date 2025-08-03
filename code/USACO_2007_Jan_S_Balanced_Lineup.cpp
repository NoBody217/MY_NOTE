#include<bits/stdc++.h>
using namespace std;

int a[101010];
int mxtree[4*101010];
int mntree[4*101010];

void buildmx(int p,int l,int r){
    if(l==r){
        mxtree[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    buildmx(p*2,l,mid);
    buildmx(p*2+1,mid+1,r);
    mxtree[p]=max(mxtree[p*2],mxtree[p*2+1]);
}
void buildmn(int p,int l,int r){
    if(l==r){
        mntree[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    buildmn(p*2,l,mid);
    buildmn(p*2+1,mid+1,r);
    mntree[p]=min(mntree[p*2],mntree[p*2+1]);
}
int calcmx(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return mxtree[p];
    }
    int mid=(l+r)>>1;
    if(x>mid) return calcmx(p*2+1,mid+1,r,x,y);
    if(y<=mid) return calcmx(p*2,l,mid,x,y);
    return max(calcmx(p*2,l,mid,x,y),calcmx(p*2+1,mid+1,r,x,y));
}
int calcmn(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return mntree[p];
    }
    int mid=(l+r)>>1;
    if(x>mid) return calcmn(p*2+1,mid+1,r,x,y);
    if(y<=mid) return calcmn(p*2,l,mid,x,y);
    return min(calcmn(p*2,l,mid,x,y),calcmn(p*2+1,mid+1,r,x,y));
}

int main(){
    memset(mxtree,-0x3f3f3f3f,sizeof(mxtree));
    memset(mntree,0x3f3f3f3f,sizeof(mntree));
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    buildmx(1,1,n);
    buildmn(1,1,n);
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << calcmx(1,1,n,l,r)-calcmn(1,1,n,l,r) << endl;    
    }
    return 0;
}