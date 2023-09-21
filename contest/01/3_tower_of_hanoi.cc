#include <iostream>
using namespace std;

int n, ans;

void print() {
  for (int i {}; i < n; ++i) {
    cout << ((ans >> i) & 1);
  }
  cout << "\n";
}

void hanoi(int i, int a, int b, int c) {
  if (i == 0) { return; }
  hanoi(i - 1, a, c, b);
  cout << a << " " << c << "\n";
  hanoi(i - 1, b, a, c);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  cout << (1 << n) - 1 << "\n";
  hanoi(n, 1, 2, 3);
  return 0;
}
