#include<stdio.h>
void printArray(int arr[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int safePoint(int nums[], int numsSize)
{
    int high = numsSize - 1;
    int spIndex = high;
    for (int i = high - 1; i >= 0; i--)
    {
        if (nums[i] >= (high - i) || nums[i] >= (spIndex - i))
        {
            nums[i] = -nums[i];
            spIndex = i;
        }
        // printf("%d ", spIndex);
    }
    if (spIndex == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int jump(int *nums, int numsSize)
{
    int range = nums[0];
    int i = 0;
    while(i<numsSize)
    {
        
    }
}

int main()
{
    int arr[14] = {9, 1, 1, 1, 1, 50, 0, 4, 0, 0, 2, 0, 1, 1};
    safePoint(arr, 14);
    printArray(arr, 14);
}