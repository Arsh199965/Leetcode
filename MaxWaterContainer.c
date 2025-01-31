#include<stdio.h>
int maxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        max = arr[i] > max ? arr[i] : max;
    }
    return max;
}
int maxArea(int *height, int heightSize)
{
    int overallMax = 0;
    int maxItem = maxElement(height, heightSize);
    int prev = 0;
    for (int i = 0; i < heightSize; i++)
    {
        if (height[prev] > height[i] || (height[prev] * (heightSize - 1 - prev) > height[i] * (heightSize - 1 - i)))
        {
            continue;
        }
        else
        {
            prev = i;
        }
        
        printf("%d\n", overallMax);
        if(overallMax> (maxItem* (heightSize-1-i)) )
        {
            break;
        }
        int currentMax = 0;
        for (int j = i+1; j < heightSize; j++)
        {
            int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            printf("->%d ", area);
            currentMax = area > currentMax ? area : currentMax;
        }
        overallMax = currentMax> overallMax ? currentMax: overallMax;
    }
    return overallMax;
}
int main()
{
    int arr[6] = {2, 8, 6, 4, 1, 9};
    printf("\n%d",maxArea(arr, 6));
}