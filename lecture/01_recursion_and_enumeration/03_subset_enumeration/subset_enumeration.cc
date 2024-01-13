#include <iostream>
using namespace std;

int n, m, ans[20];

void print() {
  cout << "{";
  if (m) { cout << ans[0]; }
  for (int i {1}; i < m; ++i) {
   cout << "," << ans[i];
  }
  cout << "}\n";
}

void dfs(int i) {
  if (i == n) { print(); return; }
  dfs(i + 1);
  ans[m++] = i;
  dfs(i + 1);
  --m;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  dfs(0);
  return 0;
}
