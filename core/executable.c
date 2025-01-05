#include "executable.h"

int see_executable_invoke(see_executable_t *c) {
  return c->function(c->context);
}
