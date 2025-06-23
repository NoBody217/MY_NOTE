#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int a[120]={0};
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    // 方法一：前后维护两个最长上升子序列
    int f1[120]={0},f2[120]={0};
    for(int i=1;i<=n;i++){
        f1[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                f1[i]=max(f1[i],f1[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        f2[i]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]){
                f2[i]=max(f2[i],f2[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f1[i]+f2[i]);
    }
    cout << n-(ans-1) << endl;
    //方法二：维护一个二维dp数组
    //第二维记录当前元素属于升序列还是降序列
    int f[120][2]={0};
    a[n+1]=-100;
    for(int i=1;i<=n+1;i++){
        f[i][0]=1;
        f[i][1]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]) f[i][0]=max(f[i][0],f[j][0]+1);
            else if(a[i]<a[j]) f[i][1]=max(f[i][1],max(f[j][0]+1,f[j][1]+1));
        }
    }
    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     ans=max(ans,max(f[i][0],f[i][1]));
    // }
    cout << n-max(f[n+1][1]-1,f[n][0]) << endl;

    return 0;
}