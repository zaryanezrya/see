#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

// Executable
typedef struct {
    void *context;
    void (*function)(void *context);
    void (*delete_context)(void *context);
} see_executable_t;

// void _see_executable_delete_context_default(void *context) {
//     free(context);
// }

// see_executable_t* see_executable_new(void (*function)(void* context)){
//     see_executable_t* executable = malloc(sizeof(see_executable_t));
//     executable->function = function;
//     executable->delete_context = _see_executable_delete_context_default;
// }

// void see_executable_delete(see_executable_t* c){
//     c->delete_context(c->context);
//     free(c);
// }

void see_executable_invoke(see_executable_t * c)
{
    c->function(c->context);
}

#endif				//SEE_EXECUTABLE_H
