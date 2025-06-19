#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* traverseDLL(node* head){
    node* temp = head;

    while (temp->next != NULL)
    {
        printf("%d\n",temp->data);
        temp= temp->next;
        
        
    };
    printf("%d\n",temp->data);
    //if the termination node of temp is NULL then i cant access the temp->prev as NULL doesnt store any value in itself, that's why we are printing the data of the last node before the loop
    do
    {
        printf("%d\n",temp->data);
        temp= temp->prev;
        
        
    }while (temp != NULL);
    


}

int main(){
    node* n1;
    node* n2;
    node* n3;
    node* n4;

    n1 = malloc(sizeof(node));
    n2 = malloc(sizeof(node));
    n3 = malloc(sizeof(node));
    n4 = malloc(sizeof(node));
    
    n1->data = 7;
    n1->prev = NULL;
    n1->next = n2;

    n2->data = 18;
    n2->prev = n1;
    n2->next = n3;

    n3->data = 69;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 99;
    n4->prev = n3;
    n4->next = NULL;

    traverseDLL(n1);
return 0;
}