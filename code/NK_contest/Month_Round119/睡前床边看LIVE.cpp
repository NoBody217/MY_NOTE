#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// 直接使用 std 命名空间
using namespace std; 

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    if (cnt.size() > 2) {
        cout << "Lie\n";
    } else if (cnt.size() == 1) {
        int K = cnt.begin()->first;

        if (K == n - 1) {
            cout << "Other\n";
        } else {
            if (2 * K > n) {
                cout << "Lie\n";
            } else {
                cout << "Other\n";
            }
        }
    } else { // cnt.size() == 2
        auto it = cnt.begin();
        int A = it->first;
        int num_A = it->second;
        it++;
        int B = it->first;

        if (B != A + 1) {
            cout << "Lie\n";
        } else if (num_A != B) {
            cout << "Lie\n";
        } else {
            cout << "Other\n";
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}