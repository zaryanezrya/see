#include "executable.h"

void see_executable_invoke(see_executable_t * c) {
  c->function(c->context);
}
