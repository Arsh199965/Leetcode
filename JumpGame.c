#include<stdio.h>
#include<stdbool.h>
bool canJump(int *nums, int numsSize)
{
    int high = numsSize - 1;
    int spIndex = high;
    for (int i = high-1; i >= 0; i--)
    {
        if (nums[i] >= (high - i) || nums[i] >= (spIndex - i))
        {
            spIndex = i;
        }
        printf("%d ",spIndex);
    }
    if(spIndex==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    int arr[9] = {2, 3, 1, 0, 10, 0, 1, 0, 4};
    printf("\n%d",canJump(arr,9));
}