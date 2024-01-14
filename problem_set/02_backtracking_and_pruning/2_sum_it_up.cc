#include <iostream>
#include <set>
#include <array>

using namespace std;

int t, n, x[12], s, m;
array<int, 12> ans;
set<array<int, 12>> ansSet;

void print() {
  if (ansSet.empty()) { cout << "NONE\n"; }
  for (auto itr {ansSet.rbegin()}; itr not_eq ansSet.rend(); ++itr) {
    auto const &a {*itr};
    for (size_t i {}; i < a.size() and a[i]; ++i) {
      cout << a[i] << "+\n"[i == a.size() - 1 or not a[i + 1]];
    }
  }
  return;
}

void dfs(int i) {
  if (i == n) {
    if (s == t) { ansSet.emplace(ans); }
    return;
  }
  s += x[i];
  ans[m++] = x[i];
  dfs(i + 1);
  s -= x[i];
  ans[--m] = 0;
  dfs(i + 1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> t >> n and n) {
    cout << "Sums of " << t << ":\n";
    for (int i {}; i < n; ++i) { cin >> x[i]; }
    dfs(0);
    print();
    ansSet.clear();
  }
  return 0;
}
