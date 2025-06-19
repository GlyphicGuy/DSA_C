#include<stdio.h>


int main(){
    int tableOf5[10];

    for (int i = 0; i < 10; i++)
    {
        tableOf5[i] = 5*(i+1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",tableOf5[i]);
    }
    
    



return 0;
}