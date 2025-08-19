#include<bits/stdc++.h>
using namespace std;


/**
 * 一圈x，跑k，先经过A后经过B
 * 如果k<x，那么只要B<=A||(B>A&&B>k)就可以
 * 如果k>x，那么B>=k-x&&B<=A
 * 如果k>2x，寄
 * 如果k=x，当且仅当B<=A
 */

void solve(){
    int k,x;
    scanf("%d%d",&k,&x);
    if(k>2*x)
        printf("0.00\n");
    else if(k>x)
        printf("%0.2lf\n",1.0*(2*x-k)*(2*x-k)/(2.0*x*x));
    else if(k==x)
        printf("0.50\n");
    else 
        printf("%0.2lf\n",1.0-(1.0*k*k/2.0)/x/x);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}