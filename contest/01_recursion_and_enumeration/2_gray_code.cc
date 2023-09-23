#include <iostream>
using namespace std;

int n, ans;

void print() {
  for (int i {}; i < n; ++i) {
    cout << ((ans >> i) & 1);
  }
  cout << "\n";
}

void dfs(int i) {
  if (i == n) { print(); return; }
  dfs(i + 1);
  ans ^= (1 << i);
  dfs(i + 1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  dfs(0);
  return 0;
}
