#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

typedef struct {
  void *context;
  void (*function)(void *context);
} see_executable_t;

void see_executable_invoke(see_executable_t *);

#endif
