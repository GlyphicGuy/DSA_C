#include<stdio.h>
#include<stdlib.h>
#include "Binary_tree_functions.h"

node* inOrderPredecessor(node* root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
    
}
node* deleteNode(node* root,int key){
    node* iPre = NULL;
    while (root!=NULL)
    {
        //base condition
        if (root->left==NULL && root->right == NULL){
                free(root);
                return NULL;
        }

        if (key< root->data)
        {
            root->left = deleteNode(root->left,key);
        }
        else if (key> root->data)
        {
            root->right = deleteNode(root->right,key);
        }
        
        //Deletition strategy when node is found
        else
        {
            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left =  deleteNode(root->left,iPre->data);
            
        }
        return root;
        
        
    }
    return NULL;
    
    
    
}

int main(){
//  Visualizing the "not" a Binary Search Tree
//        10
//       / \
//      6   12
//     / \
//    3   8
//   /
//  2
    
    node* root = createNode(10);
    node* second = createNode(6);
    node* third = createNode(12);
    node* fourth = createNode(3);
    node* fifth = createNode(8);
    node* sixth = createNode(2);

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    fourth->left = sixth;

    inOrder(root);
    deleteNode(root,8);
    printf("\n");
    inOrder(root);


return 0;
}