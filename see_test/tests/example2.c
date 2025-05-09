#include "see_test.h"

TEST(test_multiplication) {
    int c = 3 * 3;
    ASSERT(c == 9);
}

TEST(test_division) {
    int d = 10 / 2;
    ASSERT(d == 6);  // Это провалится
}