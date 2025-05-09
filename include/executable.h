#ifndef SEE_EXECUTABLE_H
#define SEE_EXECUTABLE_H

typedef struct {
  void *ctx;
  void (*execute)(void *ctx);
} executable_t;

#define EXECUTE(EXECUTABLE) EXECUTABLE.execute(EXECUTABLE.ctx)

#endif
