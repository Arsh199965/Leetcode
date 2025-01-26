#include<stdio.h>
int maxProfit(int *prices, int pricesSize)
{
    int diff = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if(prices[i]>prices[i-1])
        {
            diff = diff + (prices[i] - prices[i - 1]);
        }
    }
    return diff;
}
int main()
{
    int arr[10] = {1, 5, 3, 2, 7, 5, 8, 1, 16, 17};
    printf("%d",maxProfit(arr,10));

}