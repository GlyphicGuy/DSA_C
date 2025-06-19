#include<stdio.h>
#include<string.h>

int counter(char* str,char ch){
    int count=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ch){
            count++;
        }
    
    }
    return count;
}
int main(){
    char str[] = "hello i am not who you are.";
    printf("%d\n",counter(str,'e'));

return 0;
}