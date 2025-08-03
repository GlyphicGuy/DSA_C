#include <stdio.h>

void printArr(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    int isSorted = 1;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{

    int A[] = {22, 23, 3, 4, 99, 18};
    int n = 6;

    printArr(A);
    bubbleSort(A,n);
    printArr(A);

    return 0;
}