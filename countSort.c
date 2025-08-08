#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

void countSort(int arr[], int n, int size)
{
    int *count = (int *)malloc((n + 1) * sizeof(int));
    // initializing all elements of count[] to zero
    for (int i = 0; i < n + 1; i++)
    {
        count[i] = 0;
    }

    // counting the number of available elements of arr
    for (int i = 0; i < size; i++)
    {
        count[arr[i]] += 1;
    }

    //interating through count array and making changes to the main array
    int arrindex = 0;
    for (int i = 0; i < n + 1; i++)
    {

        while (count[i] != 0)
        {
            arr[arrindex] = i;
            arrindex++;
            count[i] -= 1;
        }
    }
}

int main()
{
    int A[] = {7, 9, 1, 3, 1, 5, 4, 2, 2,70};
    int n = sizeof(A)/sizeof(int);

    printArr(A, n);

    // printf("%d",max(A,n));
    countSort(A, max(A, n), n);
    printArr(A, n);

    return 0;
}