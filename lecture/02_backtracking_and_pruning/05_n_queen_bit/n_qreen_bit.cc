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

int MASK, ans, row[MAXN], m;

void print() {
  for (int i {}; i < m; ++i) {
    cout << row[i] << " \n"[i == m - 1];
  }
  return;
}

int lowbit(int x) { return x & -x; }

void dfs(int M, int L, int R) {
  if (M == MASK) {
    ++ans;
    // print();
    return;
  }
  int Legal = MASK & ~(M | L | R);
  for (int num {}; Legal; Legal ^= num) {
    num = lowbit(Legal);
    // row[m++] = __lg(num);
    dfs(M | num, (L | num) << 1, (R | num) >> 1);
    // --m;
  }
}

int main() {
  cin >> n;
  MASK = (1 << n) - 1;
  dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}
