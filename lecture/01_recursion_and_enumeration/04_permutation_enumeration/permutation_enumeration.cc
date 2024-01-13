#include <iostream>
using namespace std;

int n, ans[20];

void print() {
  for (int i {}; i < n; ++i) {
    cout << ans[i] << " \n"[i == (n - 1)];
  }
}

void dfs(int i) {
  if (i == n) { print(); return; }
  for (int j {i}; j < n; ++j) {
    swap(ans[i], ans[j]);
    dfs(i + 1);
    swap(ans[i], ans[j]);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i {}; i < n; ++i) { ans[i] = i; }
  dfs(0);
  return 0;
}
