#include <cstdint>
#include <cstring>
#include <iostream>
#include <sys/resource.h>

using namespace std;

size_t block_size, bound;

void stack_size_dfs(size_t depth = 1) {
  if (depth >= bound) { return; }
  int8_t ptr[block_size];
  memset(ptr, 'a', block_size);
  cout << depth << endl;
  stack_size_dfs(depth + 1);
}

void stack_size_and_runtime_error(size_t block_size, size_t bound = 1024) {
  ::block_size = block_size;
  ::bound = bound;
  stack_size_dfs();
}

void print_stack_limit() { // only work in Linux
  struct rlimit l;
  getrlimit(RLIMIT_STACK, &l);
  cout << "stack_size = " << l.rlim_cur << " byte" << endl;
}

int main () {
  // stack_size_and_runtime_error(1024, 10'000);
  print_stack_limit();
  return 0;
}
