#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int row[9], col[9], subgrids[3][3];
int grid[9][9];

void update(int r, int c, int num) {
  row[r] ^= num;
  col[c] ^= num;
  subgrids[r / 3][c / 3] ^= num;
}

void input() {
  for (int r {}; r < 9; ++r) {
    string buffer; cin >> buffer;
    for (int c {}; c < 9; ++c) {
      if (isdigit(buffer[c])) {
        grid[r][c] = 1 << (buffer[c] - '0');
        update(r, c, grid[r][c]);
      } else { grid[r][c] = 0; }
    }
  }
}

int lowbit(int x) { return (x & -x); }

bool dfs(int idx) {
  static constexpr int MASK {(1 << 10) - 2};
  if (idx == 81) { return true; }
  int r {idx / 9}, c {idx % 9};
  if (grid[r][c]) { return dfs(idx + 1); }
  int s {MASK & ~(row[r] | col[c] | subgrids[r / 3][c / 3])};
  for (int num {}; s; s ^= num) {
    num = lowbit(s);
    grid[r][c] = num;
    update(r, c, num);
    if (dfs(idx + 1)) { return true; }
    update(r, c, num);
  }
  grid[r][c] = 0;
  return false;
}

void print() {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      cout << __lg(grid[r][c]);
    }
    cout << '\n';
  }
}
int main() {
  input();
  if (dfs(0)) { print(); }
  else { cout << "No answer\n"; }
  return 0;
}
