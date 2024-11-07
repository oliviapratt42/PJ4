#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "tree.h"

BINARY_TREE* insertNode(int value, BINARY_TREE*& binary_tree);
BINARY_TREE* deleteNode(int value, BINARY_TREE*& binary_tree);
NODE* treeMinimum(NODE *node);
void transplant(BINARY_TREE *binary_tree, NODE* u, NODE* v);
void searchTree(NODE* node, int value);
void inorder(NODE *node);
void preorder(NODE *node);
void postorder(NODE *node);
void levelorder(BINARY_TREE *binary_tree);


#endif