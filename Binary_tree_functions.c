
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

//function to traverse the tree in preOrder method
void preOrder(node* root){

    if (root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    

}

//function to traverse the tree in preOrder method
void inOrder(node* root){

    if (root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    

}

node* iter_search(node* root,int key){
    while (root!=NULL)      
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else{
            root  = root->right;
        }
        
    }
    return NULL;
    
}

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