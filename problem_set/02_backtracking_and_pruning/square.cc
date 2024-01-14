#include <iostream>

using namespace std;

int N, M, x[20], x1[20], x2[20];

bool g(int *x_, int M_) {
  if (M_ <= 1) { return false; }
  int t {};
  for (int i {}; i < M_; ++i) { t += x_[i]; }
  int n {1 << (M_ - 1)};
  while (--n > -1) {
    int s {};
    for (int n_ {n}, b {}; n_; n_ &= ~b) {
      b = n_ & -n_;
      s += x_[__lg(b)];
    }
    if (t - s == s) { return true; }
  }
  return false;
}

bool f() {
  int t {};
  for (int i {}; i < M; ++i) { t += x[i]; }
  if (t & 0x3) { return false; }
  int n {1 << (M - 1)};
  while (--n > -1) {
    int s {}, M1 {}, M2 {};
    for (int i {}, m {1}; i < M; ++i, m <<= 1) {
      if (n & m) { s += x[i]; x1[M1++] = x[i]; }
      else { x2[M2++] = x[i]; }
    }
    if (t - s == s) {
      if (g(x1, M1) and g(x2, M2)) { return true; }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  while (N--) {
    cin >> M;
    for (int i {}; i < M; ++i) { cin >> x[i]; }
    cout << (f() ? "yes\n" : "no\n");
  }
  return 0;
}
