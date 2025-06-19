#include<stdio.h>
#include<string.h>


char* encrypt(char* str,int n){


    for (int i = 0; i < strlen(str); i++)
    {
        str[i]+=n;
    }
     
    return str;

}
int main(){
    
    char str[]= "bbifmmp!nfmpopojdb";
    int n;
    scanf("%d",&n);

    printf("%s",encrypt(str,n));
    
    
    

return 0;
}