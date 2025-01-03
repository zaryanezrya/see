#ifndef SEE_MAP_H
#define SEE_MAP_H

typedef struct {
    void *data;
    void *(*get)(void *data, void *key);
    void *(*insert)(void *data, void *key, void *value);
    void (*remove)(void *data, void *key);
} see_map_t;

// get
// insert
// delete

#endif
