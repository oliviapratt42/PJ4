#ifndef TREE_H

#define TREE_H

typedef struct TYPE_NODE{
    int value;
    struct TYPE_NODE *p;
    struct TYPE_NODE *left;
    struct TYPE_NODE *right;
}NODE;

typedef struct TYPE_TREE{
    NODE* root;

}BINARY_TREE;


#endif