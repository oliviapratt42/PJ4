#include "binarytree.h"
#include "tree.h"
#include <iostream>
#include <fstream> 
#include <queue>

using namespace std;

BINARY_TREE* insertNode(int value, BINARY_TREE*& binary_tree){
    NODE *new_node = new NODE;
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->p = nullptr;
    
    if (binary_tree->root == nullptr){
        binary_tree->root = new_node;
        return binary_tree;
    }

    NODE *curr_node = binary_tree->root;
    NODE *parent_node = nullptr;

    while (curr_node != nullptr){
        parent_node = curr_node;
        if (value < curr_node->value){
            curr_node = curr_node->left;
        } else{
            curr_node = curr_node->right;
        }
    }

    if (value < parent_node->value){
        parent_node->left = new_node;
    } else {
        parent_node->right = new_node;
    }

    new_node->p = parent_node;
    return binary_tree;
}
BINARY_TREE* deleteNode(int value, BINARY_TREE*& binary_tree){
    NODE *curr = binary_tree->root;
    while (curr !=nullptr && curr->value !=value){
        if (value < curr->value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr == nullptr){
        return binary_tree; //not in the tree
    }

    if (curr->left == nullptr){
        transplant(binary_tree, curr, curr->right);
    } else if (curr->right == nullptr) {
        transplant(binary_tree, curr, curr->left);
    } else {
        NODE *y= treeMinimum(curr->right);
        if (y->p != curr) {
            transplant(binary_tree, y, y->right);
            y->right = curr->right;
            y->right->p = y;
        }
        transplant(binary_tree, curr, y);
        y->left = curr->left;
        y->left->p = y;
    }
    delete(curr);
    return binary_tree;
}

NODE* treeMinimum(NODE *node){
    while (node->left !=nullptr){
        node = node->left;
    }
    return node;
}
void transplant(BINARY_TREE* binary_tree, NODE* u, NODE* v){
    if (u == binary_tree->root){
        binary_tree->root = v;
    } else if (u== u->p->left){
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    if (v != nullptr){
        v->p = u->p;
    }
}   

void searchTree(NODE *node, int value){
    if (node == nullptr){
         cout << "False\n";
         return;
    } 
    if  (value == node->value){
        cout << "True\n";
        return;
    }
    if (value < node->value){
        searchTree(node->left, value);
    }
    else {
        searchTree(node->right, value);
    }
}
void inorder(NODE *node){
    if (node != nullptr){
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
     cout << "\n";
}
void preorder(NODE *node){
    if (node != nullptr){
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
     cout << "\n";
}
void postorder(NODE *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
    cout << "\n";
}

void levelorder(BINARY_TREE* binary_tree){
    if (binary_tree->root == nullptr) {
        return;
    }
    queue<NODE*> q;
    q.push(binary_tree->root);

    while (!q.empty()){
        NODE *curr = q.front();
        q.pop();
        cout << curr->value << " ";

        if (curr->left != nullptr){
            q.push(curr->left);
        }
        if (curr->right != nullptr){
            q.push(curr->right);
        }
    }
}