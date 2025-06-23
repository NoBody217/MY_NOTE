#include<bits/stdc++.h>
using namespace std;

int a[202020];
int main(){
    int n;
    long long sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sum/=(n-1);
    for(int i=1;i<=n;i++){
        cout << sum-a[i] << ' ' ;
    }
    return 0;
}