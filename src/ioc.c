#include <string.h>

#include "see.h"

extern resolve_strategy_t resolve_strategy;

void update_resolve_strategy(var new_resolve_strategy) {
  resolve_strategy = new_resolve_strategy;
}

void default_resolve_strategy(const char *key, var ctx) {
  if (strcmp("Update resolve strategy", key) == 0) {
    ctx_update_resolve_strategy_t *_ctx = ctx;
    _ctx->executable.ctx = _ctx->new_resolve_strategy;
    _ctx->executable.execute = update_resolve_strategy;
    return;
  }
  if (strcmp("Get default resolve strategy", key) == 0) {
    ctx_get_default_resolve_strategy_t *_ctx = ctx;
    _ctx->default_resolve_strategy = default_resolve_strategy;
    return;
  }
}

resolve_strategy_t resolve_strategy = default_resolve_strategy;

void resolve(const char *key, var ctx) { resolve_strategy(key, ctx); }
