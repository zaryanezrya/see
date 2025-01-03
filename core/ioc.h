#ifndef SEE_IOC_H
#define SEE_IOC_H

#include "executable.h"

#define SEE_RESOLVE_STATUS_OK 0
#define SEE_RESOLVE_STATUS_KEY_NOT_FOUND 404

typedef struct {
  char *key;
  void *context;
} see_resolve_query_t;

int see_resolve(see_resolve_query_t *);

typedef int (*see_resolve_strategy_t)(see_resolve_query_t *);

typedef struct {
  see_resolve_strategy_t strategy;
  see_executable_t *result;
} see_update_resolve_straregy_t;

extern see_resolve_strategy_t see_resolve_strategy;

#endif
