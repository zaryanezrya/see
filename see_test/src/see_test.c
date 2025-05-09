#include "test_framework.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TESTS 100  // Можно заменить на динамический массив

static test_entry_t tests[MAX_TESTS];
static int test_count = 0;
static int tests_passed = 0;

void register_test(const char *name, void (*func)(void)) {
    if (test_count < MAX_TESTS) {
        tests[test_count].name = name;
        tests[test_count].func = func;
        test_count++;
    } else {
        fprintf(stderr, "Переполнение списка тестов\n");
        exit(1);
    }
}

void run_tests() {
    printf("=== Запуск тестов ===\n");

    for (int i = 0; i < test_count; ++i) {
        printf("%s: ", tests[i].name);
        fflush(stdout);

        tests[i].func();
        printf("OK\n");
        tests_passed++;
    }

    printf("=== Пройдено: %d из %d ===\n", tests_passed, test_count);
}