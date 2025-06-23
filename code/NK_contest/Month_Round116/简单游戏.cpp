#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]={0},idx;
    for(int i=1;i<=3;i++){
        cin >> a[i];
    }
    cin >> idx;
    int tp=a[idx];
    sort(a+1,a+4);
    if(tp==a[3]) printf("Yes");
    else printf("No");

    
}