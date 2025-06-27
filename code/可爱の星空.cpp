#include<bits/stdc++.h>

using namespace std;
/**
 * 1 0
 * 2 0
 * 3 1
 * 4 0
 * 5 2
 * 6 2
 * 7 2
 * 8 0 100
 * 9 2 101
 * 10 4 110
 * 11 4
 * 12 4
 */


long long dfs(long long n){
    if(n<=2) return 0;
    else if(n==3) return 1;
    else if(n&1) return dfs(n/2)+dfs(n/2+1)+1;
    else return dfs(n/2)*2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << dfs(n) << '\n';
    }
    return 0;
}