#include <stdio.h>

void printArr(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n)
{
    int key, j;
    // for passes
    for (int i = 1; i <= n - 1; i++)
    {
        // for each pass 
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int A[] = {22, 23, 3, 4, 99, 18};
    int n = 6;
    printArr(A);
    insertionSort(A,n);
    printArr(A);
    return 0;
}