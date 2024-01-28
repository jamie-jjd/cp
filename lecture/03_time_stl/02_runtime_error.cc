#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

void runtime_error_1() { // Segmentation fault
  int *ptr {};
  *(ptr + 7122) = 7122;
}

void runtime_error_2() { // Segmentation fault
  int *ptr {(int*)memset};
  *ptr = 7122;
}

void runtime_error_3() { // munmap_chunk(): invalid pointer
  int *ptr {(int*)memset};
  delete [] ptr;
}

void runtime_error_4() { // free(): invalid pointer
  int *ptr {new int[7122]};
  ptr += 1;
  delete [] ptr;
}

void runtime_error_5() { // maybe illegal instruction
  int a {7122}, b {};
  cout << (a / b) << "\n";
}

void runtime_error_6() { // floating point exception
  int volatile a {7122}, b {};
  cout << (a / b) << "\n";
}

void runtime_error_7() { // call to abort
  assert(false);
}

int main() {
  // runtime_error_1();
  // runtime_error_2();
  // runtime_error_3();
  // runtime_error_4();
  // runtime_error_5();
  // runtime_error_6();
  // runtime_error_7();
  return 0;
}
