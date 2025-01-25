#include<stdio.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
int removeDuplicates(int *nums, int numsSize)
{
    int mid = 0;
    int high = 0;
    int diff = 0;
    int count = 0;
    int current = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        nums[i - diff] = nums[i];
        // printArray(nums, numsSize);
        // printf("mid: %d, high: %d, current: %d, count: %d, diff: %d\n \n", mid, high, current, count, diff);
        if (nums[i] != current)
        {

            mid = i;
            high = i;
            current = nums[i];
            count = 0;
        }
        if(nums[i]==current)
        {
            count++;
            if(count<=2)
            {
                mid = i;
                
            }
            high = i;
            if(i<numsSize-1)
            {
                if (nums[i + 1] != current)
                {
                    diff = diff + (high - mid);
                }
            }
            
            
        }
        
    }
    diff = diff + (high - mid);
    return numsSize - diff;
}

int main()
{
    int arr[23] = {2,2,2,2,3,3,3,4,4,4,4,5,5,5,5,6,6,7,7,7,9,9,9};
    int newsize = removeDuplicates(arr, 23);
    printArray(arr, newsize);
}