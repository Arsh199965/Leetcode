#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        quickSort(arr, start, i);
        quickSort(arr, i + 2, end);
    }
}
int hIndex(int *citations, int citationsSize)
{
    int max = 0;
    quickSort(citations, 0, citationsSize - 1);
    for (int i = 0; i < citationsSize; i++)
    {
        if (citations[i] < citationsSize - i ? citations[i] : citationsSize - i > max)
        {
            max = citations[i] < citationsSize - i ? citations[i] : citationsSize - i;
        }
    }
    return max;
}
int main()
{
    int arr[6] = {3, 9, 6, 7, 5, 4};
    printf("%d\n", hIndex(arr, 6));
    printArray(arr, 6);
}