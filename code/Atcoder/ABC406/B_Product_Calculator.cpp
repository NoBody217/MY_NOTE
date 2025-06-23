#include<bits/stdc++.h>

using namespace std;

long long a[1010101];

int main(){
    int n, k;
    cin >> n >> k;    
    long long lmt = 1;
    for (int i = 0; i < k; ++i) {
        lmt *= 10;
    }
    lmt--;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > lmt || ans > lmt / a[i]) { // 检查是否会溢出
            ans = 1;
        } else {
            ans *= a[i];
        }
    }

    cout << ans << endl;
    return 0;
}