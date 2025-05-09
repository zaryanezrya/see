#include "see.h"

void execute(executable_t *c) {
  c->execute(c->ctx);
}
