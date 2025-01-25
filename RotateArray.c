#include<stdio.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
void rotate(int *nums, int numsSize, int k)
{
    if (k==0 || numsSize<=1)
    {
        return;
    }
    
    int rotateArr[k];
    int n = k-1;
    for (int i = numsSize-1; i >= 0; i--)
    {
        if(n>=0)
        {
            rotateArr[n] = nums[i];
            n--;
        }
        if(n<0)
        {
            if(i+k<numsSize)
            {
                nums[i + k] = nums[i];
            }
        }
        if(i<k)
        {
            nums[i] = rotateArr[i];
        }
  
    }

    
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    rotate(arr, 10, 3);
    printArray(arr, 10);
}