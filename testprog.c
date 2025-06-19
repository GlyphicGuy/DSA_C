#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int size;
    char* arr;
} stack;

stack parenthesis; // Global stack

int len(char s[]) {
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}

void push(char a) {
    if (parenthesis.top == parenthesis.size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    parenthesis.top++;
    parenthesis.arr[parenthesis.top] = a;
}

char pop() {
    if (parenthesis.top < 0) {
        return 'u'; // 'u' for underflow (stack empty)
    }
    char a = parenthesis.arr[parenthesis.top];
    parenthesis.top--;
    return a;
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    int n = len(exp);
    parenthesis.size = n;
    parenthesis.top = -1;
    parenthesis.arr = (char*)malloc(parenthesis.size * sizeof(char));

    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char check = pop();
            if (check == 'u') {
                printf("Unmatched Parenthesis! -1\n");
                free(parenthesis.arr);
                return 1;
            }
            // Check if the popped bracket matches the closing bracket
            if ((check == '(' && exp[i] != ')') ||
                (check == '[' && exp[i] != ']') ||
                (check == '{' && exp[i] != '}')) {
                printf("Unmatched Parenthesis! -2\n");
                free(parenthesis.arr);
                return 1;
            }
        }
        i++;
    }

    if (parenthesis.top != -1) {
        printf("Unmatched Parenthesis! -3\n");
        free(parenthesis.arr);
        return 1;
    }

    printf("Matched!\n");
    free(parenthesis.arr);
    return 0;
}