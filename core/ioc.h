#ifndef SEE_IOC_H
#define SEE_IOC_H

#include "executable.h"

typedef struct {
    char *key;
    void *context;
} see_resolve_query_t;

void see_resolve(see_resolve_query_t *);

typedef struct {
    void (*resolve_strategy)(see_resolve_query_t *);
    see_executable_t *result;
} see_ioc_update_resolve_straregy_t;

#endif
