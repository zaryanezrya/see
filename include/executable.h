#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

typedef struct {
  void *context;
  int (*function)(void *context);
} executable_t;

void executable_invoke(executable_t *);

#endif
