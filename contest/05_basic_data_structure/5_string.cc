#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  string X; cin >> X;
  int64_t cS {}, cT {};
  for (auto const &x : X) {
    if (x == 'T') { (cS) ? (--cS) : (++cT); }
    else { ++cS; }
  }
  cout << (cS + cT) << "\n";
  return 0;
}
