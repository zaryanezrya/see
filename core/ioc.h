#ifndef SEE_IOC_H
#define SEE_IOC_H

#include "executable.h"

typedef struct {
  char *key;
  void *context;
} see_resolve_query_t;

void see_resolve(see_resolve_query_t *);

typedef void (*see_resolve_strategy_t)(see_resolve_query_t *);

typedef struct {
  see_resolve_strategy_t strategy;
  see_executable_t *result;
} see_update_resolve_straregy_t;

extern see_resolve_strategy_t see_resolve_strategy;

#endif
