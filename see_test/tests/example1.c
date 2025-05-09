#include "see_test.h"

TEST(test_addition) {
    int a = 2 + 2;
    ASSERT(a == 4);
}

TEST(test_subtraction) {
    int b = 5 - 3;
    ASSERT(b == 2);
}