#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    if (n == 0) {
        std::cout << "YES\n";
        return;
    }

    ll debt = 0;
    ll credit = b[0];

    for (int i = 1; i < n; ++i) {
        if (b[i] > b[i-1]) {
            debt += b[i] - b[i-1];
        } else {
            credit += b[i-1] - b[i];
        }
    }

    if (credit >= debt) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}