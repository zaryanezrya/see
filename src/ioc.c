#include "../include/ioc.h"


void default_resolve_strategy(see_resolve_query_t* q){
    q->ctx = q->key;
}

void (*resolve_strategy)(see_resolve_query_t*) = &default_resolve_strategy;

void see_resolve(see_resolve_query_t* q) {
    resolve_strategy(q);
}
