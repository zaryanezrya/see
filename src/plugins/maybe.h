#ifndef SEE_MAYBE
#define SEE_MAYBE

#include "pair.h"
#include <stdbool.h>

#define generic_maybe(justT)                                                   \
  generic_pair(justT, just, bool, nothing, maybe_##justT##_t)                  \
                                                                               \
      const maybe_##justT##_t nothing_##justT =                                \
          (maybe_##justT##_t){.nothing = true};

#endif
