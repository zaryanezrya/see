#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

#define SEE_EXECUTABLE_OK 0
#define SEE_EXECUTABLE_ERROR 500

typedef struct {
  void *context;
  int (*function)(void *context);
} see_executable_t;

int see_executable_invoke(see_executable_t *);

#endif
