#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  string line;
  while (getline(cin, line)) {
    for (auto &c : line) {
      if (not isdigit(c)) { c = ' '; }
    }
    stringstream ss(line);
    int64_t x, sum {};
    while (ss >> x) { sum += x; }
    cout << sum << "\n";
  }
  return 0;
}
