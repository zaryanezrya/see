#include "ioc.h"


void default_resolve_strategy(see_resolve_query_t* q){
    q->context = q->key;
    
    // if update strategy
    // see_ioc_update_resolve_straregy_t* context = q->context;
    // context->result = see_executable_new(update_strategy);
}

// void update_strategy(void (*strategy)(see_resolve_query_t*) ) {
//     resolve_strategy = strategy;
// }

void (*resolve_strategy)(see_resolve_query_t*) = &default_resolve_strategy;

void see_resolve(see_resolve_query_t* q) {
    resolve_strategy(q);
}
