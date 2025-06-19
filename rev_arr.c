#include<stdio.h>


int main(){
    
    int arr[7] = {1, 2, 3, 4, 5,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < len/2 ; i++)
    {
        //using BITWISE XOR operator to swap
        arr[i] = arr[i] ^ arr[(len-1)-i];
        arr[(len-1)-i] = arr[i] ^ arr[(len-1)-i];
        arr[i] = arr[i] ^ arr[(len-1)-i];

    }
    //printing reversed array
    for (int i = 0; i < len; i++)
    {
        printf("%d",arr[i]);
    }
    
    
    

return 0;
}