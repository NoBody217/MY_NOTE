#include<bits/stdc++.h>

using namespace std;

/**
 * 对于一个货币系统尝试简化它，其实就是从已知的种类中尝试删掉几个
 * 可以转化为一个完全背包，背包的容积为最大的面值
 * 尝试用小的货币去表示大的货币，如果可以表示，就删除
 */
int f[25500];
int a[200];
int cmp(int a,int b){
    return a<b;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1,cmp);
        f[0]=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(f[a[i]]==1) ans++;
            for(int j=a[i];j<=a[n];j++){
                f[j]|=f[j-a[i]];
            }
        }
        cout << n-ans << endl;
    }
    return 0;
}