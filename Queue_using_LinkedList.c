#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(node *n)
{
    // this n is the created node in enqueue
    if (n == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void traverse(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }


}

void enqueue(int val)
{

    node *n = (node *)malloc(sizeof(node));
    n->data = val;
    n->next = NULL;
    if (front == NULL)
    {
        front = rear = n;
    }

    else
    {
        if (!isFull(n))
        {
            rear->next = n;
            rear = n;
        }
        else
        {
            printf("Full!\n"); // rare , only if system runns out of memory
        }
    }
}

int dequeue()
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = front;
    int val = -1; // if no value to dequeue
    if (!isEmpty(front))
    {
        front = front->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
    else
    {
        printf("Empty! Nothing to dequeue.\n");
        return val;
    }
}

int main()
{

    enqueue(34);
    enqueue(44);
    enqueue(54);
    enqueue(64);
    traverse(front);
    printf("\n");
    printf("Removing element: %d\n",dequeue());
    traverse(front);
    return 0;
}