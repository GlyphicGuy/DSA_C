#include<stdio.h>


int main(){
    int num;
    FILE* ptr;
    ptr = fopen("aqudam.txt","r");

    fscanf(ptr,"%d",&num);
    // fprintf(ptr,"%d",num); can be used to write in "w" mode. Also write mode deletes the older contents of the file and then writes the new everytime. soln? use "a" mode for appending.
    fclose(ptr);
    fscanf(ptr,"%d",&num);
    printf("%d\n",num);

return 0;
}