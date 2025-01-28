#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int m)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *ptr = (int *)malloc(sizeof(int) * 2);
    int x = 0;
    int y = 1;
    while (y < numbersSize && x <= y)
    {
        printf("x: %d, y: %d ", x, y);
        if (numbers[x] + numbers[y] == target)
        {
            ptr[0] = x + 1;
            ptr[1] = y + 1;
            break;
        }
        
        if (y+1<numbersSize && numbers[x] + numbers[y + 1] <= target)
        {
            y++;
            
        }
        else if (numbers[x] + numbers[y] > target)
        {
            y--;
        }
        else
        {
            x++;
        }
        
        
    }
    *returnSize = 2;
    return ptr;
}
int main()
{
    int arr[3] = {2, 3, 4};
    int sum = 6;
    int r;
    int *returnSize = &r;
    int *twosummed = twoSum(arr, 3, sum, returnSize);
    printArray(twosummed, *returnSize);
}