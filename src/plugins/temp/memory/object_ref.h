#include <stdlib.h>

typedef struct object_ref_t {
  int ref_count;
  void *object;
} object_ref_t;

object_ref_t *create_object_ref(void *object) {
  object_ref_t *o = (object_ref_t *)malloc(sizeof(object_ref_t));
  o->ref_count = 1;
  o->object = object;
  return o;
}

object_ref_t *object_ref_count_incr(object_ref_t *o) {
  o->ref_count++;
  return o;
}

object_ref_t *object_ref_count_decr(object_ref_t *o) {
  o->ref_count--;
  return o;
}
