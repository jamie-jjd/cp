#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool row[9][10], col[9][10], subgrids[3][3][10];
int grid[9][9];

void update(int r, int c, int num, bool val) {
  row[r][num] = col[c][num] = subgrids[r / 3][c / 3][num] = val;
}

void input() {
  for (int r {}; r < 9; ++r) {
    string buffer; cin >> buffer;
    for (int c {}; c < 9; ++c) {
      if (isdigit(buffer[c])) {
        grid[r][c] = buffer[c] - '0';
        update(r, c, grid[r][c], true);
      } else { grid[r][c] = 0; }
    }
  }
}

bool illegal(int r, int c, int num) {
  return row[r][num] or col[c][num] or subgrids[r / 3][c / 3][num];
}

bool check() {
  for (int r {}; r < 9; ++r) {
    for (int c {}; c < 9; ++c) {
      if (grid[r][c] == 0) { continue; }
      if (illegal(r, c, grid[r][c])) { return false; }
      update(r, c, grid[r][c], true);
    }
  }
  return true;
}

bool dfs(int idx) {
  if (idx == 81) { return true; }
  int r {idx / 9}, c {idx % 9};
  if (grid[r][c]) { return dfs(idx + 1); }
  for (int num {1}; num <= 9; ++num) {
    if (illegal(r, c, num)) { continue; }
    grid[r][c] = num;
    update(r, c, num, true);
    if (dfs(idx + 1)) { return true; }
    update(r, c, num, false);
  }
  grid[r][c] = 0;
  return false;
}

void print() {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      cout << grid[r][c];
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
