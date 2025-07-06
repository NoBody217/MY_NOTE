#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
    int sum1=0,sum2=0;
    for(int i=0;i<5;i++) {cin >> a[i];sum1+=a[i];}
    for(int i=0;i<5;i++) {cin >> b[i];sum2+=b[i];}
    if(sum1+a[0]>sum2+b[4])cout << "YES" ;
    else cout << "NO" ;
    return 0;
}