#include <string.h>
#include "ioc.h"

extern see_resolve_strategy_t see_resolve_strategy;

int see_update_resolve_strategy(void *ctx) {
  see_resolve_strategy = (see_resolve_strategy_t) ctx;
  return SEE_EXECUTABLE_INVOKE_STATUS_OK;
}

int default_resolve_strategy(see_resolve_query_t *q) {
  if (strcmp("Update IoC strategy", q->key) == 0) {
    see_update_resolve_straregy_t *qctx = q->context;
    qctx->result->context = qctx->strategy;
    qctx->result->function = see_update_resolve_strategy;
    return SEE_RESOLVE_STATUS_OK;
  }
  return SEE_RESOLVE_STATUS_KEY_NOT_FOUND;
}

see_resolve_strategy_t see_resolve_strategy = default_resolve_strategy;

int see_resolve(see_resolve_query_t *q) {
  return see_resolve_strategy(q);
}
