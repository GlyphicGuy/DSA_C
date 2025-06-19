#include<stdio.h>
#include<string.h>

struct emp
{
    int code;
    float sal;
    char name[20];
};

void show (struct emp e){
    printf("Code: %d\n",e.code);
    printf("Salary: %.2f\n",e.sal);
    printf("Name: %s\n",e.name);
}

int main(){
    
    struct emp e;

    e.code = 777;
    e.sal = 100.45;
    strcpy(e.name,"aqudam");
    
    show(e);
return 0;
}