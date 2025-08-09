#include<stdio.h>
#include "Binary_tree_functions.h"

int isBST(node* root){
    static node* prev = NULL;
    if (root!=NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && prev->data >= root->data) //inOrder traversal so checking for it being in ascending order
        {
            return 0; // the if conditions are to catch if it's not in ascending order
        }
        prev = root;
        return isBST(root->right);
        
    }
    else{
        return 1;
    }
    
}
//  Visualizing the "not" a Binary Search Tree
//        10
//       / \
//      6   9
//     / \
//    3   8  

int main(){
    
    node* root = createNode(10);
    node* second = createNode(6);
    node* third = createNode(9);
    node* fourth = createNode(3);
    node* fifth = createNode(5);
    
    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;

    if (isBST(root))
    {
        printf("It is a Binary Search Tree!");
    }else
    {
        printf("Nope...Not a BST.");
    }

/* To run this userdefined header included file:

>>> gcc check_BST.c Binary_tree_functions.c -o check_BST

creates an executable: check_BST

>>> ./check_BST
to run the executable

*/

return 0;
}