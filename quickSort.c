#include <stdio.h>

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >  pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    int pivotIndex;
    if (low < high)
    {
        pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{

    int A[] = {2,1,80,9,4,80,22,75,60,2};
    int n = 10;

    printArr(A, n);

    quickSort(A, 0, n - 1);
    printArr(A, n);

    return 0;
}