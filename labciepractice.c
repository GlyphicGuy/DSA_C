#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* concat(char str1[],char str2[]){

    int i,j;
    char* str3 = malloc(200*sizeof(char));
    
        for ( i = 0; i < strlen(str1); i++)
        {
            str3[i] = str1[i];
        }
        for ( j = 0; j < strlen(str2); j++)
        {
            str3[i] = str2[j];
            i++;
        }
        str3[i] = (char)0;
    
    return str3 ;
}



int main(){
    
    // printf("%s",concat("hello","duniya"));
    // printf("%c",concat("hello","duniya")[10]);

    int r, c;
    int m[5][5], trans[5][5];
    int i,j;

    scanf("%d %d", &r, &c);
    for ( i = 0; i < r; i++)
    {
        scanf("%d ",mat[])
    }
    
return 0;
}