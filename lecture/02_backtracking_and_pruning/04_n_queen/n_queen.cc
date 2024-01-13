#include <iostream>
using namespace std;

constexpr int MAXN {20};
constexpr int MAXM {(MAXN << 1) - 1};

bool column_has_queen[MAXN];
bool LD_RU_Diagonal[MAXM];
bool LU_RD_Diagonal[MAXM];

int n; // input

void update(int y, int x, bool val) {
  column_has_queen[x] = val;
  LD_RU_Diagonal[y + x] = val;
  LU_RD_Diagonal[n - 1 + (y - x)] = val;
}

bool isValidQueenPosition(int y, int x) {
  if (column_has_queen[x])
    return false;
  if (LD_RU_Diagonal[y + x])
    return false;
  if (LU_RD_Diagonal[n - 1 + (y - x)])
    return false;
  return true;
}

int ans, row[MAXN], m;

void print() {
  for (int i {}; i < m; ++i) {
    cout << row[i] << " \n"[i == m - 1];
  }
  return;
}

void dfs(int y) {
  if (y == n) {
    ++ans;
    // print();
    return;
  }
  for (int x {}; x < n; ++x) {
    if (not isValidQueenPosition(y, x)) { continue; }
    update(y, x, true);
    // row[m++] = x;
    dfs(y + 1);
    update(y, x, false);
    // --m;
  }
  return;
}

int main() {
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
}
