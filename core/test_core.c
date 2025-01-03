#include <assert.h>

#include "ioc.h"

// ---

typedef struct {
  int a;
  int b;
  int res;
} binop_context_t;

int add_positive_function(void *context) {
  binop_context_t *ctx = context;

  if (ctx->a < 0 || ctx->b < 0) {
    return SEE_EXECUTABLE_ERROR;
  } else {
    ctx->res = ctx->a + ctx->b;
    return SEE_EXECUTABLE_OK;
  }
}

void test_executable_ok() {
  binop_context_t ctx = { 150, 150 };
  see_executable_t p = { &ctx, add_positive_function };

  assert(see_executable_invoke(&p) == SEE_EXECUTABLE_OK);
  assert(ctx.res == 150 + 150);
}

void test_executable_err() {
  binop_context_t ctx = { -100, 101 };
  see_executable_t p = { &ctx, add_positive_function };

  assert(see_executable_invoke(&p) == SEE_EXECUTABLE_ERROR);
}

// ---

int resolve_strategy(see_resolve_query_t * q) {
  q->context = q->key;
  return SEE_RESOLVE_OK;
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
  assert(see_resolve(&q_update_strategy) == SEE_RESOLVE_OK);
  assert(see_resolve_strategy != resolve_strategy);
  assert(see_executable_invoke(&update) == SEE_EXECUTABLE_OK);
  assert(see_resolve_strategy == resolve_strategy);

  see_resolve_query_t q_test = {
    "PUT ME IN THE CONTEXT"
  };
  assert(q_test.key != q_test.context);
  assert(see_resolve(&q_test) == SEE_RESOLVE_OK);
  assert(q_test.key == q_test.context);
}

// ---

int main() {
  test_executable_ok();
  test_executable_err();
  test_update_resolve_strategy();

  return 0;
}
