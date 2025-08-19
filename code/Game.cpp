#include<bits/stdc++.h>
using namespace std;

int prime[100000];
int vis[100000];
int cnt=0;

void sieve(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;
            prime[++cnt]=i;

        }
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>lim||vis[i*prime[j]]) break;
            vis[i*prime[j]]=vis[i]+vis[prime[j]];
        }
    }
}

int main(){
    int n;
    cin >> n;
    sieve(n);
    cout << (vis[n]%2?"Nancy":"Johnson") << endl;
}