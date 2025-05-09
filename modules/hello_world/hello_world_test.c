#include <assert.h>
#include "hello_world.h"

void test_add_2_plus_2_equals_4() {
  int a = 2;
  int b = 2;
  int res = add(a, b);
  assert(res == 4);
}

// ---

int main() {
  test_add_2_plus_2_equals_4();

  return 0;
}