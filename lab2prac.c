#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
    int top;
    char *s;
}stack;
struct stack st;
char infix[100],postfix[100];

void push(struct stack *st,char c){
    st->top+=1;
    st->s[st->top]=c;
}

char pop(struct stack *st)
{
    st->top-=1;
    return st->s[st->top+1];
};

int isEmpty(struct stack st){
    if(st.top==-1){
        return 1;
    }
    else
        return 0;
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')'){
        return 1;
    }
    else
        return 0;
};

int precedence(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c == '('){
        return 0 ;
    }
}

void infixToPostfix(char infix[],char postfix[]){
    
    push(&st,'(');
    
    // Append ')' to the end of infix expression
    int len = strlen(infix);
    infix[len] = ')';
    infix[len+1] = '\0';
    
    int i, j = 0;  // Initialize j to 0
    for (i = 0; infix[i] != '\0'; i++)  // Remove extra i++ at end
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else{
            if (infix[i] == ')')
            {
                while (st.s[st.top] != '(')
                {
                    postfix[j] = pop(&st);
                    j++;
                }
                pop(&st); // Pop the '(' from stack
            }
            else if (infix[i] == '(')
            {
                push(&st, infix[i]);
            }
            else if (precedence(st.s[st.top]) < precedence(infix[i]))
            {
                push(&st, infix[i]);
            }
            else{
                while (precedence(st.s[st.top]) >= precedence(infix[i]))
                {
                    postfix[j] = pop(&st);
                    j++;
                }
                push(&st, infix[i]); // Push the current operator
            }
        }
    }
    postfix[j] = '\0'; // Null terminate the postfix string
}

int main(){

    st.s = (char *)malloc(100*sizeof(char));
    st.top = -1;
    printf("enter the infix string: ");
    scanf("%s",infix);

    infixToPostfix(infix,postfix);

    printf("%s",postfix);

return 0;
}