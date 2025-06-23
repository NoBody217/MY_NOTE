#include<bits/stdc++.h>
using namespace std;

long long a[2020202];
/**
 * 处理l到r的前缀和
 * 只考虑进位
 */

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,q;
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=q;i++){
            int l,r;
            cin >> l >> r;
            long long sum=a[l];
            for(int j=l;j<=r;j++){
                sum=sum-(sum^a[j])+a[j];
            }
            cout << sum << endl;
        }

    }

    return 0;
}