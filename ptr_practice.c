#include<stdio.h>

int tentimes(int* n){
    return *n * 10;
}


int main(){
    int num =5;
printf("%d",tentimes(&num));

return 0;
}