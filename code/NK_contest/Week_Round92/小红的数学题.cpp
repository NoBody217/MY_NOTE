#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int k;
    cin >> k;
    //丢精度过不了
    // int p = 2*((int)sqrt(k+1))-2;
    // for(;p<k;p++){
    //     int delt=p*p-4*(k-p);
    //     if(delt<0)continue;
    //     else{
    //         if(sqrt(delt)*sqrt(delt)==delt) cout << p << ' ' << k-p ;
    //         return 0;
    //     }
    // }
    // cout << -1 ;
    int up=sqrt(k+1);
    for(int i=2;i<=up;i++){
        if((k+1)%i==0){
            int p=(i-1)+((k+1)/i-1);
            cout << p << ' ' << k-p <<endl; 
            return 0;
        }
    }
    cout << -1 ;
    return 0;
}