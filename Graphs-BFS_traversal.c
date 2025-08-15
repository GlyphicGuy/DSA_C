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
        printf("overflow!\n");
    }
    
}

int dequeue(queue *k1)
{
    if (!isEmpty(k1))
    {
        int temp = (k1->arr)[(k1->front)+1];
        k1->front++;
        return temp;
    }
    else
    {
        printf("underflow!\n");
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
    queue q;
    q.size = 3;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int visited[3] = {0,0,0};

    int adjMatrix[3][3] = {
        {0,1,1},
        {1,0,1},
        {1,1,0}   
    };

    int i = 2;
    int node;

    printf("%d ",i);
    visited[i] = 1;
    enqueue(&q,i);

    while (!isEmpty(&q))
    {
        node = dequeue(&q);
        for (int j = 0; j < 3; j++)
        {
            if (adjMatrix[node][j]== 1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
            
        }
        
    }
    



    

    return 0;
}