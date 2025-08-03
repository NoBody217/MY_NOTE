//本题c++还得高精度，遂逃，选择python

#include<bits/stdc++.h>
using namespace std;


unsigned long long f[300];


void deal(int x){
    f[1]=0,f[2]=1;
    for(int i=3;i<=x;i++){
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
}

int mp[220][220];
int main(){
    int n;
    cin >> n ;
    deal(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }
    cout << f[n];
    return 0;
}