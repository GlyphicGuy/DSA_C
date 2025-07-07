#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// w
typedef struct stack
{
    int top;
    char *s;
} stack;

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
        return 0;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
}

int isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *s, char c)
{
    s->top += 1;
    s->s[s->top] = c;
}

char pop(struct stack *s)
{
    char c = s->s[s->top];
    s->top -= 1;
    return c;
}

int main()
{
    char infix[100];
    char postfix[100];
    printf("enter the infix string: ");
    scanf("%s", infix);

    stack s;

    s.s = (char *)malloc(strlen(infix) * sizeof(char));
    s.top = -1;
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (isEmpty(s))
            {
                push(&s, infix[i]);
            }

            else if (precedence(infix[i]) > precedence(s.s[s.top]))
            {
                push(&s, infix[i]);
            }
            else
            {
                postfix[j] = pop(&s);
                j++;
                push(&s, infix[i]);
            }

            i++;
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(&s);
        j++;
    }
    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}