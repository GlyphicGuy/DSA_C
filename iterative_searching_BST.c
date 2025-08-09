#include<stdio.h>
#include "Binary_tree_functions.h"

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
    node* fifth = createNode(5);
    
    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;

    int n = 1;  //key to search
    
    if (iter_search(root,n) == NULL)
    {
        printf("Key not found. Either root = NULL or key not in tree.\n");
    }
    else{
        printf("Key '%d' found!\n",iter_search(root,n)->data);
    }


return 0;
}