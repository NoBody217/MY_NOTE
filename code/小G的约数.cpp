#include<bits/stdc++.h>
using namespace std;

long long g(long long n){
    long long ans=0;
    for(int i=1;i<=n;){
        long long s=n/i;
        long long r=n/s;
        ans+=s*(i+r)*(r-i+1)/2;
        i=r+1;
    }
    return ans;
}

int main(){
    long long n;
    cin >> n;
    cout << g(g(n));
    return 0;
}