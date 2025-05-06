#ifndef SEE_ALLOCATOR_H
#define SEE_ALLOCATOR_H

#include <stdlib.h>

typedef struct {
  void *ctx;
  void *(*malloc)(void *ctx, size_t size);
  void *(*calloc)(void *ctx, size_t number, size_t size);
  void *(*realloc)(void *ctx, void *ptr, size_t size);
  void (*free)(void *ctx, void *ptr);
} see_allocator_t;

#endif
