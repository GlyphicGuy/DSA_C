#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int sum =0;
    int arr[5];
    for (int i =0; i<5; i++) {
        arr[i]= n % (int)pow(10, i + 1); 
        if (i!=0) {
        
        sum = sum + ((arr[i]-arr[i-1] )/(10*i));
        // printf("%d",sum);
        }else{
            sum += arr[i];
        }
    }
    printf("%d",sum);

    
    
    
    return 0;
}