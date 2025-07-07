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
    if (k1->rear == (k1->size - 1) && k1->front == -1)
    {
        return 0;
    }

    if (k1->rear == k1->front)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *k1)
{
    if (k1->rear == (k1->size - 1) && k1->front == -1)
    {
        return 1;
    }

    if (((k1->rear + 1) % (k1->size)) == k1->front)
    {
        return 1;
    }

    return 0;
}

void enqueue(queue *k1, int val)
{
    if (!isFull(k1))
    {
        k1->rear = (k1->rear + 1) % (k1->size);
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
        k1->front = (k1->front + 1) % k1->size;
    }
    else
    {
        printf("underflo!\n");
    }
}

void printqueue(queue k1)
{

    int i = k1.front;
    while (i != k1.rear)
    {
        printf("%d[%d] ", (k1.arr)[(i + 1) % k1.size], (i + 1) % k1.size);

        i = (i + 1) % k1.size;
    }

    printf("\n");
}

int main()
{

    queue k1;
    k1.size = 5;
    k1.front = k1.rear = -1;
    k1.arr = (int *)malloc(k1.size * sizeof(int));

    enqueue(&k1, 12);
    enqueue(&k1, 78);
    enqueue(&k1, 34);
    enqueue(&k1, 68);
    enqueue(&k1, 18);
    // checking overflo
    enqueue(&k1, 19);
    enqueue(&k1, 20);

    // printing the queue
    printqueue(k1);

    // dequeueing
    dequeue(&k1);
    dequeue(&k1);
    dequeue(&k1);

    // printing the queue
    printqueue(k1);

    // inserting more elements
    enqueue(&k1, 19);
    enqueue(&k1, 20);

    // printing the queue
    printqueue(k1);
    // checking overflo again
    enqueue(&k1, 55);
    enqueue(&k1, 99);

    /* one element in the circular queue remains empty for the front, only initially it is -1 that also can be changed to 0 and has the same scenario except for the first round of enqueue*/

    return 0;
}