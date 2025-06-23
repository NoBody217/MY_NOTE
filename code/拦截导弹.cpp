#include<bits/stdc++.h>
using namespace std;

int a[101010];
int f1[101010];
int f2[101010];
int main(){
    int cnt=1;
    while (cin >> a[cnt++]);
    for(int i=1;i<cnt;i++){
        for(int j=1;j<i;j++){
            if(a[i]<a[j]){
                f1[i]=max(f1[i],f1[j]+1);
            }
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                f2[i]=max(f2[i],f2[j]+1);
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<cnt;i++){
        ans1=max(ans1,f1[i]); 
        ans2=max(ans2,f2[i]); 
    }
    cout << ans1 << endl << ans2 <<endl;
    return 0;
}