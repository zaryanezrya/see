#include "executable.h"

void executable_execute(executable_t *c) {
  c->execute(c->ctx);
}
