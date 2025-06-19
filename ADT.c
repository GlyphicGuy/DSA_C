#include<stdio.h>
#include<stdlib.h>

typedef struct myArray{

    int total_size;
    int used_size;
    int* ptr;

}myarr;

void insert(myarr* a,int element,int index){

    // 0 1 2 3 
    if (index>(a->total_size) -1)
   {
    printf("Index out of bound\n");
   }

    for (int i = (a->used_size); i > index; i--)
    {
        (a->ptr)[i]=(a->ptr)[i-1];
    }
    a->ptr[index] = element;
    a->used_size +=1;
    

}

void delete(myarr* a,int index){
   // 0 1 2 3 3

   if (index>(a->total_size) -1)
   {
    printf("Index out of bound\n");
   }

   
    for (int i = index; i < (a->used_size)-1; i++)
    {
        (a->ptr)[i]=(a->ptr)[i+1];
    }
    
    a->used_size -=1;
    

}

void printarr(myarr* arr){

    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ",(arr->ptr)[i]);
    }
}

int main(){
    
    myarr* arr;
    arr = (myarr*)malloc(sizeof(myarr));
    arr->total_size = 10;
    arr->used_size = 4;
    arr->ptr = (int*)malloc(arr->total_size * sizeof(int));
    
    for (int i = 0; i < arr->used_size; i++)
    {
        (arr->ptr)[i]=i;
    }
    printarr(arr);
    printf("\n");

    insert(arr,9,2);
    printarr(arr);
    printf("\n");
    
    delete(arr,2);
    printarr(arr);
    printf("\n");
    

return 0;
}