#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;

} queue;

int isEmpty(queue *k1)
{
    if (k1->front == k1->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *k1)
{
    if (k1->rear == (k1->size) - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *k1, int val)
{
    if (!isFull(k1))
    {
        k1->rear += 1;
        k1->arr[k1->rear] = val;
    }
    else
    {
        printf("overflo!\n");
    }
    
}

void dequeue(queue *k1)
{
    if (!isEmpty(k1))
    {
        k1->front++;
        // free(&k1->arr[k1->front]);
    }
    else
    {
        printf("underflo!\n");
    }
}

void printqueue(queue k1){

    for (int i = k1.front +1; i <= k1.rear; i++)
    {
        printf("%d ",(k1.arr)[i]);
    }
    printf("\n");
} 

int main()
{
    queue k1;
    k1.size = 7;
    k1.front = k1.rear = -1;
    k1.arr = (int *)malloc(k1.size * sizeof(int));

    
//testing operations:
    printqueue(k1);
    enqueue(&k1, 18);
    enqueue(&k1, 12);
    enqueue(&k1, 27);
    enqueue(&k1, 93);
    enqueue(&k1, 1);
    enqueue(&k1, 23);
    enqueue(&k1, 76);
    enqueue(&k1, 69);

    printqueue(k1);

    dequeue(&k1);
    dequeue(&k1);

    printqueue(k1);
    

    return 0;
}