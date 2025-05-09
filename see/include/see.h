#ifndef SEE_H
#define SEE_H

// General

typedef void* var;

// Executable

typedef struct {
  var ctx;
  void (*execute)(var ctx);
} executable_t;

void execute(executable_t *c);

// IoC

void resolve(const char *key, var ctx);

typedef void (*resolve_strategy_t)(const char *key, var ctx);

typedef struct {
  resolve_strategy_t new_resolve_strategy;
  executable_t executable;
} ctx_update_resolve_strategy_t;

typedef struct {
  resolve_strategy_t default_resolve_strategy;
} ctx_get_default_resolve_strategy_t;

#endif
