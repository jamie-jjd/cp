#include <algorithm>
#include <iostream>
using namespace std;

int64_t n, s, t, m, p[20];

void dfs(int i) {
  if (i == n) {
    auto d {(s < t) ? (t - s) : (s - t)};
    if (d < m) { m = d; }
    return;
  }
  s -= p[i]; t += p[i];
  dfs(i + 1);
  s += p[i]; t -= p[i];
  dfs(i + 1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i {}; i < n; ++i) {
    cin >> p[i]; s += p[i];
  }
  m = s;
  dfs(0);
  cout << m << "\n";
  return 0;
}
