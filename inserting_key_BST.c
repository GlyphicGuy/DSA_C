#include<stdio.h>
#include "Binary_tree_functions.h"

void insertKey(node* root, int key){

    node* newNode = createNode(key);
    node* prev;
    while (root!=NULL)
    {
        prev = root; //this points to the prev node, required later
        if (root->data == key)
        {
            printf("Key already exists!\n");
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }   
    }
    if (key< prev->data)
    {
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }
}

int main(){
//  Visualizing the "not" a Binary Search Tree
//        10
//       / \
//      6   12
//     / \
//    3   8  
    
    node* root = createNode(10);
    node* second = createNode(6);
    node* third = createNode(12);
    node* fourth = createNode(3);
    node* fifth = createNode(8);
    
    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;

    int n = 7;

    insertKey(root,n);

//checkig the insertion by running a inOrder traversal
    inOrder(root);
return 0;
}