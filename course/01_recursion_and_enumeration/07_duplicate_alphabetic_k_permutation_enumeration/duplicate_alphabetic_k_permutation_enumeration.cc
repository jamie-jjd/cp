#include <algorithm>
#include <iostream>
using namespace std;

int n, k, a[20], ans[20];
bool visit[20];

void print() {
  for (int i {}; i < k; ++i) {
    cout << ans[i] << " \n"[i == (k - 1)];
  }
}

void dfs(int i) {
  if (i == k) { print(); return; }
  for (int j {}, prev = -1; j < n; ++j) {
    if (visit[j] or prev == a[j]) { continue; }
    visit[j] = true;
    ans[i] = prev = a[j];
    dfs(i + 1);
    visit[j] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i {}; i < n; ++i) { cin >> a[i]; }
  sort(a, a + n);
  dfs(0);
  return 0;
}
