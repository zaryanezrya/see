#include "pool_allocator.h"

pool_t *pool_ctor(size_t chunk_size, size_t capacity) {
  pool_t *pool = malloc(sizeof(pool_t));
  pool->memory = malloc(chunk_size * capacity);
  pool->chunk_size = chunk_size;
  pool->capacity = capacity;
  pool->length = 0;

  pool_chunk_t *cursor = pool->memory;
  for (int i = 0; i < capacity; i++) {
    _pool_push(pool, cursor);
    cursor += chunk_size;
  }
}

void pool_dtor(pool_t *pool) {
  free(pool->memory);
  free(pool);
}

void *pool_alloc(pool_t *pool) { return _pool_pop(pool); }

void pool_free(pool_t *pool, void *ptr) { _pool_push(pool, ptr); }

void _pool_push(pool_t *pool, void *ptr) {
  if (ptr) {
    pool_chunk_t *chunk = ptr;
    chunk->next = pool->next;
    pool->next = chunk;
    pool->length--;
  }
}

void *_pool_pop(pool_t *pool) {
  pool_chunk_t *chunk = pool->next;
  if (!chunk) {
    return NULL;
  }
  pool->next = chunk->next;
  return chunk;
}
