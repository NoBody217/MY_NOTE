#include<bits/stdc++.h>
using namespace std;
/**
 * 只要0101，1010
 */
int cnt0[600],cnt1[600];
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cnt0[i]=cnt0[i-1]+(s[i]=='0');
        cnt1[i]=cnt1[i-1]+(s[i]=='1');
    }
    int ans=0x3f3f3f3f;
    for(int i=2;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                ans=min(ans,
                    min(cnt0[i-1]+(cnt1[j-1]-cnt1[i-1])+(cnt0[k-1]-cnt0[j-1])+(cnt1[n]-cnt1[k-1]),
                    cnt1[i-1]+(cnt0[j-1]-cnt0[i-1])+(cnt1[k-1]-cnt1[j-1])+(cnt0[n]-cnt0[k-1])));
            }
        }
    }
    cout << ans << endl;
    return 0;
}