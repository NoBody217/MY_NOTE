#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  auto mp = vector(N + 2, string(M + 2, '1'));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> mp[i][j];
    }
  }
  auto visit1 = vector(N + 2, vector(M + 2, false));
  auto visit2 = vector(N + 2, vector(M + 2, false));
  auto dot = vector(N + 2, vector(M + 2, false));

  auto dfs1 = [&](auto &self, int x, int y) -> void {
    if (mp[x][y] == '1') return;
    if (visit1[x][y]) return;
    visit1[x][y] = true;
    self(self, x + 1, y);
    self(self, x - 1, y);
    self(self, x, y + 1);
  };
  dfs1(dfs1, 1, 1);

  auto dfs2 = [&](auto &self, int x, int y) -> void {
    if (mp[x][y] == '1') return;
    if (visit2[x][y]) return;
    visit2[x][y] = true;
    self(self, x + 1, y);
    self(self, x - 1, y);
    self(self, x, y - 1);
  };
  dfs2(dfs2, 1, M);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      dot[i][j] = visit1[i][j] && !visit2[i][j];
    }
  }

  auto visit = vector(N + 2, vector(M + 2, false));

  auto search = [&](auto &self, int x, int y, int width) -> int {
    visit[x][y] = true;
    int a1 = 1, a2 = 1, a3 = 1;
    if (!visit[x + 1][y] && dot[x + 1][y])
      a1 = self(self, x + 1, y, width);
    if (!visit[x - 1][y] && dot[x - 1][y])
      a2 = self(self, x - 1, y, width);
    if (!visit[x][y + 1] && dot[x][y + 1])
      a3 = self(self, x, y + 1, width + 1);
    return max({a1, a2, a3, width});
  };

  int maxwidth = 0;
  for (int j = 1; j <= M; j++) {
    for (int i = 1; i <= N; i++) {
      if (dot[i][j] && !visit[i][j])
        maxwidth = max(maxwidth, search(search, i, j, 1));
    }
  }

  // cout << maxwidth << endl;

  if (maxwidth < K)
    cout << "No\n";
  else
    cout << "Yes\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}