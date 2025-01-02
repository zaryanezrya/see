#ifndef SEE_CALLABLE_H
#define SEE_CALLABLE_H

typedef struct {
    void* context;
    void (*function)(void* context);
} see_callable_t;

void see_call(see_callable_t* c){
    c->function(c->context);
}

#endif // SEE_CALLABLE_H
