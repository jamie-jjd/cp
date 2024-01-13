#include <iostream>
using namespace std;

int64_t t, n, r[25], c[25], p[25], a[5], b[5];
int64_t m;

void check() {
  int64_t s {};
  for (int64_t i {}; i < n; ++i) {
    int64_t d {10};
    for (int64_t j {}; j < 5; ++j) {
      auto r1 {a[j] / 5}, c1 {a[j] % 5};
      auto dr {(r[i] < r1) ? (r1 - r[i]) : (r[i] - r1)};
      auto dc {(c[i] < c1) ? (c1 - c[i]) : (c[i] - c1)};
      if (dr + dc < d) { d = dr + dc; }
    }
    s += d * p[i];
  }
  if (s < m) {
    m = s;
    for (int64_t i {}; i < 5; ++i) {
      b[i] = a[i];
    }
  }
}

void dfs(int64_t i, int64_t j) {
  if (i == 5) { check(); return; }
  for (; j < 25; ++j) {
    a[i] = j;
    dfs(i + 1, j + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    m = 1;
    for (int64_t i {}; i < n; ++i) {
      cin >> r[i] >> c[i] >> p[i];
      m += 10 * p[i];
    }
    dfs(0, 0);
    for (int64_t i {}; i < 5; ++i) {
      cout << b[i] << " \n"[i == 4];
    }
  }
  return 0;
}
