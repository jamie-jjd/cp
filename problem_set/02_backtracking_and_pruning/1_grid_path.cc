#include <iostream>
#include <string>

using namespace std;

string s;
bool vst[9][9];
int i, ans;

void init() {
  for (int j {}; j < 9; ++j) {
    vst[j][0] = vst[j][8] = vst[0][j] = vst[8][j] = true;
  }
}

void dfs(int i, int r, int c) {
  if (vst[r][c]) { return; }
  if (r == 7 and c == 1) { ans += (i == 48); return; }
  if (i == 48) { ans += (r == 7 and c == 1); return; }
  if (vst[r][c - 1] and vst[r][c + 1] and not vst[r - 1][c] and
      not vst[r + 1][c]) { return; }
  if (not vst[r][c - 1] and not vst[r][c + 1] and vst[r - 1][c] and
      vst[r + 1][c]) { return; }
  vst[r][c] = true;
  if (s[i] == '?') {
    int const dr[4] {0, 1, 0, -1};
    int const dc[4] {-1, 0, 1, 0};
    for (int j {}; j < 4; ++j) { dfs(i + 1, r + dr[j], c + dc[j]); }
  } else if (s[i] == 'L') { dfs(i + 1, r, c - 1); }
  else if (s[i] == 'D') { dfs(i + 1, r + 1, c); }
  else if (s[i] == 'R') { dfs(i + 1, r, c + 1); }
  else if (s[i] == 'U') { dfs(i + 1, r - 1, c); }
  vst[r][c] = false;
  return;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s;
  init();
  dfs(0, 1, 1);
  cout << ans << "\n";;
  return 0;
}
