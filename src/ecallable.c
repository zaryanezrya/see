#include <stdio.h>

#include "../include/callable.h"

int add(int a, int b)
{
    return a+b;
}

typedef struct {
    int a;
    int b;
    int res;
} add_context_t;

void add_function(void* context){
    add_context_t* ctx = context;
    ctx->res = ctx->a + ctx->b;
}

int main()
{
    add_context_t ctx;
    see_callable_t p = {&ctx, add_function};

    ctx.a = 101;
    ctx.b = 100;
    see_call(&p);

    printf("%i", ctx.res);

    return 0;
}