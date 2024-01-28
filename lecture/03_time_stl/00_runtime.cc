#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

double speed(int iter_num) {
  static constexpr int BLOCK_SIZE {1024};
  int volatile A[BLOCK_SIZE];
  auto begin {steady_clock::now()};
  while (iter_num--) {
    for (int j {}; j < BLOCK_SIZE; ++j) { A[j] += j; }
  }
  return duration_cast<duration<double>>(steady_clock::now() - begin).count();
}

int main () {
  cout << speed(420'000) << "\n";
  return 0;
}
