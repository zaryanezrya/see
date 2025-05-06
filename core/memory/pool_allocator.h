#ifndef SEE_POOL_ALLOCATOR_H
#define SEE_POOL_ALLOCATOR_H

#include <stdlib.h>

typedef struct pool_t {
  pool_chunk_t *next;
  void *memory;
  size_t chunk_size;
  size_t capacity;
  size_t length;
} pool_t;

typedef struct pool_chunk_t {
  pool_chunk_t *next;
} pool_chunk_t;

pool_t *pool_ctor(size_t chunk_size, size_t chunk_number);
void pool_dtor(pool_t *pool);

void *pool_alloc(pool_t *pool);
void pool_free(pool_t *pool, void *ptr);

#endif