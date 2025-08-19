#include<bits/stdc++.h>

using namespace std;

long long get_weight(int x){
    long long ans=0;
    for(int i=0;i<=31;i++){
        if((x>>i)&1){
            ans+=pow(3,i);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int k;
        cin >> k;
        printf("Case #%d: %lld\n",i,get_weight(k));
    }
    return 0;
}