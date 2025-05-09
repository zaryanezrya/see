#include "hello_world.h"
#include <stdio.h>

int add(int a, int b) { return a + b; }

void init() {
  printf("Hello, world!\n");
  printf("2+2=%i\n", add(2, 2));
}
