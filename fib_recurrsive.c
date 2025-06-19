#include <stdio.h>

int fib(int n){

    if(n ==1 || n==2){
        return n-1;
    }
    return fib(n-1) + fib(n-2);

    // int n1 = 0;
    // int n2 = 1;
    // int n3 = 0;
    // for(int i=2;i<n;i++){
    //     n3 = n1 + n2;
    //     n1=n2;
    //     n2 = n3;
        
    //     // 0 1 1 2 3 5 8
    // }
    // return n3;

}

int main(){
    printf("%d  ",fib(100));
    printf(" ");
    return 0;
    
}