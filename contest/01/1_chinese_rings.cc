#include <iostream>
using namespace std;

int count;
void print(int i, bool out) {
  ++count;
  cout << "Move ring " << i << ((out) ? " out\n" : " in\n");
}

void dfs(int n, bool out) {
  if (n <= 2) {
    if (out) { for (int i {n}; i; --i) { print(i, true); } }
    else { for (int i {1}; i <= n; ++i) { print(i, false); } }
    return;
  }
  if (out) {
    dfs(n - 2, true);
    print(n, true);
    dfs(n - 2, false);
    dfs(n - 1, true);
  }
  else {
    dfs(n - 1, false);
    dfs(n - 2, true);
    print(n, false);
    dfs(n - 2, false);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  dfs(n, true);
  cout << count << "\n";
  return 0;
}
