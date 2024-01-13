#include <iostream>
#include <string>
using namespace std;

bool row[9][10], col[9][10], subgrids[3][3][10];
int grid[9][9];

void input() {
  for (int r {}; r < 9; ++r) {
    string buffer; cin >> buffer;
    for (int c {}; c < 9; ++c) {
      grid[r][c] = buffer[c] - '0';
    }
  }
}

bool illegal(int r, int c, int num) {
  return row[r][num] or col[c][num] or subgrids[r / 3][c / 3][num];
}

void update(int r, int c, int num, bool val) {
  row[r][num] = col[c][num] = subgrids[r / 3][c / 3][num] = val;
}

bool check() {
  for (int r {}; r < 9; ++r) {
    for (int c {}; c < 9; ++c) {
      if (illegal(r, c, grid[r][c])) { return false; }
      update(r, c, grid[r][c], true);
    }
  }
  return true;
}

int main() {
  input();
  cout << (check() ? "Yes\n" : "No\n");
  return 0;
}
