#include <assert.h>

#include "ioc.h"

// ---

int add(int a, int b) {
  return a + b;
}

typedef struct {
  int a;
  int b;
  int res;
} add_context_t;

void add_function(void *context) {
  add_context_t *ctx = context;

  int a = ctx->a;
  int b = ctx->b;
  int res = add(a, b);

  ctx->res = res;
}

void test_executable() {
  add_context_t ctx = { 100, 101 };
  see_executable_t p = { &ctx, add_function };

  see_executable_invoke(&p);

  assert(ctx.res == 201);
}

// ---

void resolve_strategy(see_resolve_query_t * q) {
  q->context = q->key;
}

void test_update_resolve_strategy() {
  see_executable_t update;
  see_update_resolve_straregy_t ctx = {
    resolve_strategy,
    &update
  };
  see_resolve_query_t q_update_strategy = {
    "Update IoC strategy",
    &ctx
  };
  see_resolve(&q_update_strategy);
  assert(see_resolve_strategy != resolve_strategy);
  see_executable_invoke(&update);
  assert(see_resolve_strategy == resolve_strategy);

  see_resolve_query_t q_test = {
    "PUT ME IN THE CONTEXT"
  };
  assert(q_test.key != q_test.context);
  see_resolve(&q_test);
  assert(q_test.key == q_test.context);
}

// ---

int main() {
  test_executable();
  test_update_resolve_strategy();

  return 0;
}
