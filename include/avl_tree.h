#ifndef SEE_AVL_TREE_H
#define SEE_AVL_TREE_H

#define NULL ((void*)0)

typedef struct {
    int key;
    avl_tree_node_t *left;
    avl_tree_node_t *right;
    int height;
} avl_tree_node_t;

int avl_tree_node__get_height(avl_tree_node_t * node)
{
    return (node == NULL) ? 0 : node->height;
}

avl_tree_node_t *avl_tree__rotate_left(avl_tree_node_t * a)
{
    avl_tree_node_t *b = a->right;
    avl_tree_node_t *c = b->left;

    a->right = c;
    b->left = a;

    return b;
}

avl_tree_node_t *avl_tree__rotate_right(avl_tree_node_t * node)
{

}

#endif
