#include <algorithm>
#include <iostream>
using namespace std;

int n, k, a[23], ans[23];

void print() {
  for (int i {}; i < k; ++i) {
    cout << ans[i] << " \n"[i == (k - 1)];
  }
}

void dfs(int i, int j) {
  if (i == k) { print(); return; }
  for (int prev = -1; j < n; ++j) {
    if (prev == a[j]) { continue; }
    ans[i] = prev = a[j];
    dfs(i + 1, j + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i {}; i < n; ++i) { cin >> a[i]; }
  sort(a, a + n);
  dfs(0, 0);
  return 0;
}
