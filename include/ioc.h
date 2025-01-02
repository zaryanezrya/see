#ifndef SEE_IOC_H
#define SEE_IOC_H

#include "callable.h"

typedef struct {
    char* key;
    void* ctx;
} see_resolve_query_t;

void see_resolve(see_resolve_query_t*);

typedef struct {
    void (*resolve_strategy)(see_resolve_query_t*);
    see_callable_t* result;
} see_resolve_ctx_update_resolve_straregy_t;

#endif
