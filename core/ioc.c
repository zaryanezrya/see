#include "ioc.h"

int strcmp(const char *s1, const char *s2) {
  unsigned char uc1, uc2;
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }

  uc1 = (*(unsigned char *) s1);
  uc2 = (*(unsigned char *) s2);
  return ((uc1 < uc2) ? -1 : (uc1 > uc2));
}

int see_update_resolve_strategy(void *ctx) {
  see_resolve_strategy_t new_strategy = ctx;
  see_resolve_strategy = new_strategy;
  return SEE_EXECUTABLE_OK;
}

int default_resolve_strategy(see_resolve_query_t * q) {
  if (strcmp("Update IoC strategy", q->key) == 0) {
    see_update_resolve_straregy_t *qctx = q->context;
    qctx->result->context = qctx->strategy;
    qctx->result->function = see_update_resolve_strategy;
    return SEE_RESOLVE_OK;
  }
  return SEE_RESOLVE_KEY_NOT_FOUND;
}

see_resolve_strategy_t see_resolve_strategy = default_resolve_strategy;

int see_resolve(see_resolve_query_t * q) {
  return see_resolve_strategy(q);
}
