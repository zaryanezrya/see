#include <assert.h>

#include "see.h"

// ---

typedef struct {
  int a;
  int b;
  int *res;
} binop_context_t;

void add_positive_function(void *context) {
  binop_context_t *ctx = context;

  if (ctx->a > 0 && ctx->b > 0) {
    *(ctx->res) = ctx->a + ctx->b;
  }
}

void test_see_executable_ok() {
  int res = 0;
  binop_context_t ctx = {150, 150, &res};
  executable_t p = {&ctx, add_positive_function};

  assert(res == 150 + 150);
}

// ---

// void test_see_resolve_key_not_found() {
//   see_resolve_query_t q = {
//       "DEFINITELY DOESN'T EXIST",
//   };
//   assert(see_resolve(&q) == SEE_RESOLVE_STATUS_KEY_NOT_FOUND);
// }

// int resolve_strategy(see_resolve_query_t *q) {
//   q->context = q->key;
//   return SEE_RESOLVE_STATUS_OK;
// }

// void test_see_update_ioc_strategy() {
//   see_executable_t update;
//   see_update_resolve_straregy_t ctx = {resolve_strategy, &update};
//   see_resolve_query_t q_update_strategy = {"Update IoC strategy", &ctx};
//   assert(see_resolve(&q_update_strategy) == SEE_RESOLVE_STATUS_OK);
//   assert(see_executable_invoke(&update) == SEE_EXECUTABLE_INVOKE_STATUS_OK);

//   see_resolve_query_t q_test = {"PUT ME IN THE CONTEXT"};
//   assert(q_test.key != q_test.context);
//   assert(see_resolve(&q_test) == SEE_RESOLVE_STATUS_OK);
//   assert(q_test.key == q_test.context);
// }

// ---

// generic_pair(int, a, int, b, pair_int_int_t);

// void test_pair() {
//   pair_int_int_t p = {1, 2};
//   assert(p.a == 1);
//   assert(p.b == 2);
// }

// ---

// generic_maybe(int);
// void test_maybe() {
//   maybe_int_t m;
//   assert(nothing_int.nothing == 1);
// }

// ---

int main() {
  // test_see_executable_error();
  test_see_executable_ok();
  // test_see_resolve_key_not_found();
  // test_see_update_ioc_strategy();
  // test_pair();
  // test_maybe();

  return 0;
}
