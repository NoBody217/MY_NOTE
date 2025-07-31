#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  priority_queue<int> pq;
  int n, k, c;
  cin >> n >> k >> c;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    pq.emplace(a[i] - i * c);
  }
  int answer = 0;
  for (int i = 0; i < k; i++) {
    answer += pq.top();
    pq.pop();
  }
  answer += k * (k - 1) / 2 * c;
  cout << answer << endl;
  return 0;
}