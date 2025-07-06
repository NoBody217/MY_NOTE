#include<bits/stdc++.h>

using namespace std;

int vis[1020];
int main(){
    int t;
    cin >> t;
    while(t--){
        int tp,k;
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<5;i++){
            cin >> tp;
            if(tp!=0){
                vis[tp]++;
                sum++;
            }
        }
        cin >> k;
        if(sum==0)cout << "1/1000" << endl;
        else if(sum==vis[k])cout << "1/1"<< endl;
        else cout << vis[k]/gcd(sum,vis[k]) << '/' << (vis[k]==0?1:sum/gcd(sum,vis[k])) << endl;
    }
    return 0;
}