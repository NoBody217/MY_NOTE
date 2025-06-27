#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            printf("%4d",cnt++);
        }
        printf("\n");
    }
    return 0;
}