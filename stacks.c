#include<stdio.h>
#include<stdlib.h>

typedef struct stacks
{
   int size;
   int top;
   int* arr;

}stack;

int isfull(stack* s){
    if (s->top == (s->size) -1)
        return 1;
    else
        return 0;
}

int isempty(stack* s){
    if (s->top<0)
        return 1;
    else
        return 0;
}

void push(stack* s, int element){
    if (isfull(s)==0)
    {
        s->arr[(s->top)+1] = element;
        s->top++;
    }
    
}

void printStack(stack s){
    for(int i = 0; i<=s.top;i++){
        printf("%d ",s.arr[i]);
    }

}

int pop(stack* s){
    if (isempty(s) == 0)
    {
        s->top--;
        return 0;
    }
    
}


int main(){
    
    stack s;
    s.size = 50;
    s.top = -1;
    s.arr = malloc(s.size * sizeof(int));

    push(&s,7);
    push(&s,9);
    push(&s,2);
    push(&s,4);
    printStack(s);
    printf("\n");
    pop(&s);
    printStack(s);

    

return 0;
}