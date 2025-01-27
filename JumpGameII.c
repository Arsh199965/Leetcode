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
    if (safePoint(nums, numsSize)==0)
        return 0;
    int range = -nums[0];
    int newrange = 0;
    int newIndex = 0;
    int jumps = 0;
    int i = 1;
    while(i<numsSize)
    {
        if(range>=numsSize-1)
        {
            jumps++;
            break;
        }
        if(i<=range)
        {
            if(nums[i]<0)
            {
                if (i + (-nums[i]) > newrange)
                {
                    newrange = i + (-nums[i]);
                    newIndex = i;
                }
            }
            
            i++;
        }
        else
        {
            i = newIndex;
            range = newrange;
            newrange = i;
            jumps++;
        }
    }
    return jumps;
}

int main()
{
    int arr[14] = {9, 1, 1, 1, 1, 5, 0, 4, 0, 0, 2, 0, 1, 1};
    printf("%d",jump(arr,14));
    
}