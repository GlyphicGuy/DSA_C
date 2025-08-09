
#include <stdio.h>
#include <stdlib.h>
#include "Binary_tree_functions.h"
//function to create the node of the tree
struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}