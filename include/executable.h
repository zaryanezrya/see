#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

typedef struct {
  void *ctx;
  void (*execute)(void *ctx);
} executable_t;

void execute(executable_t *c);

#endif
