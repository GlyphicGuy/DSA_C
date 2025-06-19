#include<stdio.h>

typedef struct employee
{
    char name[10];
    int sal;

}emp;


int main(){
    
    FILE* ptr;
    ptr = fopen("aqudam.txt","r");

    /*Q1.
    int num[3];
    fscanf(ptr,"%d",&num[0]);
    fscanf(ptr,"%d",&num[1]);
    fscanf(ptr,"%d",&num[2]);

    printf("%d\n",num[0]);
    printf("%d\n",num[1]);
    printf("%d\n",num[2]);
    */

    /*Q2
    int n = 5;
    
    for (int i = 1; i <= 10; i++)
    {
        fprintf(ptr,"%dx%d=%d\n",n,i,n*i);
    }
    */

    /*Q3
    emp e[2];
    
    for (int i = 0; i < 2; i++)
    {
        scanf("%s",e[i].name);
        scanf("%d",&e[i].sal);
    }
    
    FILE* emp = fopen("emp.txt","w");
    
    for (int i = 0; i < 2; i++)
    {
        fprintf(emp,"%s,",e[i].name);
        fprintf(emp,"%d\n",e[i].sal);
    }
    */
    /*Q4
    int num;
    fscanf(ptr,"%d",&num);
    
    ptr = fopen("aqudam.txt","w");
    
    fprintf(ptr,"%d",num*2);
    */
fclose(ptr);



    



return 0;
}