#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
/**
 * 前i组能不能凑出j
 * dp[i][j]=dp[i-1][j+{a[i].first~a[i].second}]
 * 双层枚举i,j,对于每一个j枚举区间，O(100*1000000*100)=O(1e10)
 * 过不了一点
 *  for(int i=1;i<=n;i++){
        for(int j=1;j<1e6;j++){
            for(int k=a[i].first;k<=a[i].second;k++){
                dp[i][j]=dp[i-1][j-k*k]
            }
        }
    }
 * bitset优化
 */
const int N = 1e6+10;
pii a[120];
bitset<N> dp[120];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >>a[i].second;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i].first;j<=a[i].second;j++){
            dp[i]|=(dp[i-1]<<(j*j));
        }
    }
    cout << dp[n].count() << '\n';
    return 0;
}