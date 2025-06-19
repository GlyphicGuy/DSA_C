#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} node;

int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(node *top)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *push(node *top, int data)
{

    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Stack Overflow");
    }

    else
    {

        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
    return top;
}

void pop(node **top)
{

    if (top == NULL)
    {
        printf("Stack Underflo!");
    }

    else
    {
        node *n = malloc(sizeof(node));
        n = *top;
        *top = (*top)->next;
        free(n);
    }
}
/*in the below approach i have used node** top instead of node* top so that i
dont have to return the top pointer from the function and assign back to top in
main as did in push, just another approach by not returning from the func, else
use the push() similar method of node*
you can also make top a global variable after header files but look into that
the local variable should not have the same name as global*/

void traverse(node *top)
{
    node *temp;
    temp = top;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int peek(node *top,int pos)
{
    node *temp;
    temp = top;
    int count = 1;
    while (count != pos && temp != NULL)
    {
        temp = temp->next;
        count++;
        
    }
    return temp->data;
    
}

int main()
{
    node *top;
    node *second;
    node *third;
    node *fourth;

    top = malloc(sizeof(node));
    second = malloc(sizeof(node));
    third = malloc(sizeof(node));
    fourth = malloc(sizeof(node));

    top->data = 7;
    top->next = second;

    second->data = 18;
    second->next = third;

    third->data = 69;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = NULL;

    top = push(top, 19);
    printf("All the elements are:\n");
    traverse(top);

    printf("After popping:\n");
    pop(&top);
    traverse(top);

    printf("Peeked element at position 3 is: %d\n",peek(top,3));

    return 0;
}