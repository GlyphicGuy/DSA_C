#include<stdio.h>
#include<stdlib.h>


//defining the structure of the node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

//function to create the node of the tree
struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


int main(){

    //initializing the nodes
    node* root = createNode(7);
    node* second = createNode(2);
    node* third = createNode(5);
    node* fourth = createNode(1);
    node* fifth = createNode(1);

//  Visualizing the Binary Tree
//        7
//       / \
//      2   5
//     / \
//    1   1  

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;

return 0;
}