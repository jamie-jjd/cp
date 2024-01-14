#include <iostream>
#include <string>
using namespace std;

constexpr int MAXN {20};
constexpr int MAXM {(MAXN << 1) - 1};
constexpr int n {8};

bool column_has_queen[MAXN];
bool LD_RU_Diagonal[MAXM];
bool LU_RD_Diagonal[MAXM];
bool isReserved[n][n];

void update(int y, int x, bool val) {
  column_has_queen[x] = val;
  LD_RU_Diagonal[y + x] = val;
  LU_RD_Diagonal[n - 1 + (y - x)] = val;
}

bool isValidQueenPosition(int y, int x) {
  if (isReserved[y][x]) { return false; }
  if (column_has_queen[x]) { return false; }
  if (LD_RU_Diagonal[y + x]) { return false; }
  if (LU_RD_Diagonal[n - 1 + (y - x)]) { return false; }
  return true;
}

int ans, row[MAXN], m;

void dfs(int y) {
  if (y == n) {
    ++ans;
    return;
  }
  for (int x {}; x < n; ++x) {
    if (not isValidQueenPosition(y, x)) { continue; }
    update(y, x, true);
    dfs(y + 1);
    update(y, x, false);
  }
  return;
}

int main() {
  string s;
  for (int r {}; r < n; ++r) {
    cin >> s;
    for (int c {}; c < n; ++c) { isReserved[r][c] = (s[c] == '*'); }
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}
