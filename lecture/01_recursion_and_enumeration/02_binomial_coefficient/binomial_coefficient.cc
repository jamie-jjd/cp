#include <iostream>
using namespace std;

int C(int n, int k) {
  if (k == 0 or k == n) { return 1; }
  return C(n - 1, k) + C(n - 1, k - 1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;
  cout << C(n, k) << "\n";
  return 0;
}
