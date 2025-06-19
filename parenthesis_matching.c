#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int size;
    char* arr;
}stack;

stack parenthesis;
//just declaring the stack glaobally makes its inside variables accessible globally

int len(char s[]){
    int count=0;
    while (s[count]!= '\0'){
        count++;
    }
    return count;    
}

void push(){
    parenthesis.top++;
    // printf("%d",parenthesis.top);
    parenthesis.arr[parenthesis.top] == '(';
}
int pop(){
    if(parenthesis.top<0){
        return -1;
    }else{
        parenthesis.top--;
        return 0;
    }
}


int main(){
    
    int n,i=0;
    char exp[100];
    scanf("%s",exp);
    n=len(exp);
    parenthesis.size = n;
    //making size = array size will help us from stack overflow case, see line 45 malloc of size n
    parenthesis.top = -1;
    parenthesis.arr = malloc(parenthesis.size*sizeof(char));

    while(exp[i]!='\0'){
        
        if (exp[i] == '('){
            push();
        }else if(exp[i] == ')'){
            if (pop() == -1){
                printf("Unmatched Parenthesis!");
                return 1; //returning 1 for unmatched
            }
        }
        i++; 
    }
    if(parenthesis.top!= -1){
        printf("Unmatched Parenthesis!");
        return 1;
    }
    printf("Matched!");
    
return 0; //returning 0 for matched. just for ref doenst hold imp
}