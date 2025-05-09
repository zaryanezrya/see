#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>

// Структура теста
typedef struct {
    const char *name;
    void (*func)(void);
} test_entry_t;

// Регистрация теста
void register_test(const char *name, void (*func)(void));

// Запуск всех тестов
void run_tests();

// Макрос для объявления теста
#define TEST(name) \
    void name(); \
    static void __attribute__((constructor)) _register_##name() { register_test(#name, name); } \
    void name()

// Макрос для проверки
#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            printf(" [ПРОВАЛ: %s], %s:%d\n", #condition, __FILE__, __LINE__); \
            return; \
        } \
    } while (0)

#endif // TEST_FRAMEWORK_H