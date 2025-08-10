// Binary_tree_functions.h
#ifndef Binary_tree_functions_h
#define Binary_tree_functions_h

//defining the structure of the node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

struct node* createNode(int data);
void preOrder(node* root);
void inOrder(node* root);
node* iter_search(node* root,int key);
node* recur_search(node* root,int key);

#endif