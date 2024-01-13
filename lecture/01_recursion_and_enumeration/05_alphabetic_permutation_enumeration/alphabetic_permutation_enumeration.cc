#include <iostream>
using namespace std;

int n, ans[20];
bool visit[20];

void print() {
  for (int i {}; i < n; ++i) {
    cout << ans[i] << " \n"[i == (n - 1)];
  }
}

void dfs(int i) {
  if (i == n) { print(); return; }
  for (int j {}; j < n; ++j) {
    if (visit[j]) { continue; }
    visit[j] = true;
    ans[i] = j;
    dfs(i + 1);
    visit[j] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i {}; i < n; ++i) { ans[i] = i; }
  dfs(0);
  return 0;
}
