#include <algorithm>
#include <iostream>
using namespace std;

string a, b;
vector<string> ans;
vector<bool> visit;

void dfs(size_t i) {
  if (i == a.size()) {
    ans.emplace_back(b);
    return;
  }
  char prev {};
  for (size_t j {}; j < a.size(); ++j) {
    if (visit[j] or prev == a[j]) { continue; }
    visit[j] = true;
    b[i] = prev = a[j];
    dfs(i + 1);
    visit[j] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> a;
  sort(a.begin(), a.end());
  b = a;
  visit.resize(a.size(), false);
  dfs(0);
  cout << ans.size() << "\n";
  for (auto const &s : ans) { cout << s << "\n"; }
  return 0;
}
