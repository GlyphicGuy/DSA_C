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

void push(char a){
    if (parenthesis.top == parenthesis.size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    parenthesis.top++;
    // printf("%d",parenthesis.top);
    parenthesis.arr[parenthesis.top] = a;
}
char pop(){
    if(parenthesis.top<0){
        return 'u';
    }
    char a = parenthesis.arr[parenthesis.top];
    parenthesis.top--;
    return a;
    
}


int main(){
    
    int n,i=0;
    char exp[100];
    scanf("%s",exp);
    n=len(exp);
    parenthesis.size = n;
    //making size = array size will help us from stack overflow case, see line 45 malloc of size n
    parenthesis.top = -1;
    parenthesis.arr = (char*)malloc(parenthesis.size*sizeof(char));

    while(exp[i]!='\0'){
        
        if (exp[i] == '(' || exp[i] == '['  || exp[i] == '{' ){
            push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == ']'  || exp[i] == '}'){
            // printf(" %d",parenthesis.top);
            char check = pop();
            // printf(" %c",check);
            if (check == 'u'){
                printf("Unmatched Parenthesis! -1 ");
                free(parenthesis.arr);
                return 1; //returning 1 for unmatched
            }
            
                if ((check == '(' && exp[i] != ')') ||
                (check == '[' && exp[i] != ']') ||
                (check == '{' && exp[i] != '}'))
                {
                    
                  
                    printf("Unmatched Parenthesis! -2");
                    free(parenthesis.arr);
                    return 1;
                }
                
            
        }
        i++; 
    }
    if(parenthesis.top!= -1){
        printf("Unmatched Parenthesis!-3");
        free(parenthesis.arr);
        return 1;
    }
    printf("Matched!");
    free(parenthesis.arr);
    
return 0; //returning 0 for matched. just for ref doenst hold imp
}