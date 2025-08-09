#include<stdio.h>
#include "Binary_tree_functions.h"

node* recur_search(node* root,int key){

    if (root==NULL)
    {
        return NULL;
    }
    else if (root->data == key )
    {
        return root;
    }
    else if (root->data > key)
    {
        return recur_search(root->left,key);
    }
    else
    {
        return recur_search(root->right,key);
    }

    return NULL;
    
    
}

int main(){

//  Visualizing the "not" a Binary recur_search Tree
//        10
//       / \
//      6   12
//     / \
//    3   8  
    
    node* root = createNode(10);
    node* second = createNode(6);
    node* third = createNode(12);
    node* fourth = createNode(3);
    node* fifth = createNode(5);
    
    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;

    int n = 12;
    
    if (recur_search(root,n) == NULL)
    {
        printf("Key not found. Either root = NULL or key not in tree.");
    }
    else{
        printf("Key '%d' found!",recur_search(root,n)->data);
    }
    

return 0;
}