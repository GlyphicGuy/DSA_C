#include<stdio.h>

int visited[3] = {0,0,0};

int adjMatrix[3][3] = {
        {0,1,1},
        {1,0,1},
        {1,1,0}   
};

void DFS(int i){
    printf("%d ",i);
    visited[i] = 1;
    for (int j = 0; j < 3; j++)
    {
        if (adjMatrix[i][j] ==1 && !visited[j])
        {
            DFS(j);
        }
        
    }
//functions call themselves in stack so no need to implement stack for the geting the work done.
    
}

int main(){
    
    DFS(2); //takes the node to start from as the argument

return 0;
}