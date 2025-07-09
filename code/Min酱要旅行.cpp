#include<bits/stdc++.h>
const int N = 2330;
using namespace std;

/**
 * 要求k件物品，第i件不能带，容积为1~m的方案数
 * 转化为先求k件物品，容积为m的01背包
 * 再求k件物品，必须带第i件的01背包
 * 相减即可得到k件物品，第i件不带的情况
 * 
 * f求第一个背包
 * f[i]表示k件物品装满容积i，方案数
 * f[i]+=f[i-a[j]]
 * g求第二个背包
 * g[i]表示容积为i，不带某件方案数
 * g[i-a[j]]就表示容积为i，必带a[j]的方案数
 * g[i]+=f[i]-g[i-a[j]]表示容积为i不带a[j]
 * 
 */

int f[N],g[N],a[N];
int main(){
    int n,m;
    while(cin >> n >> m){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        f[0]=1;
        for(int i=0;i<n;i++){
            for(int j=m;j>=0;j--){
                if(j-a[i]>=0)
                    f[j]+=f[j-a[i]]%10;
            }
        }

        for(int i=0;i<n;i++){//不带a[i]
            for(int j=0;j<=m;j++){
                if(j<a[i]) g[j]=f[j];
                else g[j]=(f[j]%10-g[j-a[i]]%10+10)%10;
            }
            for(int j=1;j<=m;j++){
                cout << g[j]%10;
            }
            cout << endl;
        }
        
    }
    return 0;
}