#include <stdlib.h>

#ifndef SEE_MAP_H
#define SEE_MAP_H

typedef struct {
    char* key;
    void* value;
} see_map_item_t;

typedef struct {
    int size;
    see_map_item_t* data;
} see_map_t;


see_map_t* see_map_new(){
    see_map_t* map;
    map = (see_map_t*)malloc(sizeof(see_map_t));
    map->size = 0;
    map->data = NULL;
}


#endif // SEE_MAP_H