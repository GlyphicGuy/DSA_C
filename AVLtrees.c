#include<stdio.h>
#include<stdlib.h>

typedef struct AVLnode{
    int key;
    struct AVLnode* left;
    struct AVLnode* right;
    int height;

}AVLnode;

AVLnode* createNode(int key){
    AVLnode* newNode = (AVLnode*)malloc(sizeof(AVLnode));
    newNode->height=1;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
}

int getHeight(AVLnode* node){
    if (node ==NULL)
        return 0;
    
    return node->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int balaceFactor(AVLnode* node){
    return getHeight(node->left) - getHeight(node->right);
}

AVLnode* rightRotate(AVLnode* x){
    AVLnode* y = x->left;
    AVLnode* t2 = y->right;

    //rotation
    y->right = x;
    x->left = t2;

    //heights updation
    x->height = 1+ max(getHeight(x->left),getHeight(x->right));
    y->height = 1+ max(getHeight(y->left),getHeight(y->right));

    return y;
}

AVLnode* leftRotate(AVLnode* y){
    AVLnode* x = y->right;
    AVLnode* t2 = x->left;

    //rotation
    x->left = y;
    y->right = t2;

    //heights updation
    x->height = 1+ max(getHeight(x->left),getHeight(x->right));
    y->height = 1+ max(getHeight(y->left),getHeight(y->right));

    return x;
}

AVLnode* insertNode(AVLnode* node,int key){
    //Standard BST insertion
    if (node==NULL)
    {
        return createNode(key);
    }
    
    if (key < node->key)
    {
        node->left = insertNode(node->left,key);
    }
    else if (key > node->key)
    {
        node->right = insertNode(node->right,key);
    }
    else{
        return node; //Duplicate node found
    }

    //updating the height
    node->height = 1 + max(getHeight(node->left),getHeight(node->right));
    //finding the balance factor
    int bf = balaceFactor(node);

    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    else if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    else if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    
    return node;
    
}

void inOrder(AVLnode* root){
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
    
}

int main(){

    AVLnode* root = NULL;

    root = insertNode(root,20);
    root = insertNode(root,8);
    root = insertNode(root,25);
    root = insertNode(root,15);
    root = insertNode(root,10);
    root = insertNode(root,30);
    root = insertNode(root,22);

    
    inOrder(root);
    printf("\n");

return 0;
}