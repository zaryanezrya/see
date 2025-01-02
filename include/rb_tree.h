#ifndef SEE_RB_TREE_H
#define SEE_RB_TREE_H

#define NULL ((void*)0)

typedef struct {
    int key;
    void *data;
    rb_tree_node_t *parent;
    rb_tree_node_t *left;
    rb_tree_node_t *right;
} rb_tree_node_t;

#endif				// SEE_RB_TREE_H
