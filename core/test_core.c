#include <assert.h>

#include "ioc.h"

int add(int a, int b)
{
    return a + b;
}

typedef struct {
    int a;
    int b;
    int res;
} add_context_t;

void add_function(void *context)
{
    add_context_t *ctx = context;

    int a = ctx->a;
    int b = ctx->b;
    int res = add(a, b);

    ctx->res = res;
}

void test_executable()
{
    add_context_t ctx = { 100, 101 };
    see_executable_t p = { &ctx, add_function };

    see_executable_invoke(&p);

    assert(ctx.res == 201);
}

// ---

void resolve_strategy(see_resolve_query_t * q)
{
    q->context = q->key;
}

void test_ioc_update_strategy()
{
    see_executable_t result;
    see_update_resolve_straregy_t ctx = {
	resolve_strategy,
	&result
    };
    see_resolve_query_t q = {
	"Update IoC strategy",
	&ctx
    };
    // see_executable_invoke(&result);
}

// ---

int main()
{
    test_executable();
    test_ioc_update_strategy();

    return 0;
}
