#include<stdio.h>
void printArray(int arr[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int m, int brr[], int n)
{
    if(m==0)
    {
        for (int k = 0; k < n; k++)
        {
            arr[k] = brr[k];
        }
        
    }
    int i = 0;
    while(i<n)
    {
        int j=m-1+i;
        int flag = 0;
        while(j>=0 && !flag )
        {
            printArray(arr, 10);

            printf("i: %d, j: %d\n",i,j);
            if (arr[j]> brr[i])
            {
                arr[j + 1] = arr[j];
                arr[j] = brr[i];
                
            }
            else if (arr[j]<=brr[i])
            {
                if(arr[j+1]!=brr[i])
                {
                    arr[j + 1] = brr[i];
                }
                flag = 1;
            }
            j--;
            
            
        }
        i++;
    }
    
}



int main()
{
    int arr[10] = {1, 2, 4, 6, 8,0,0,0,0,0};
    int brr[5] = {2, 3, 5, 7, 9};
    merge(arr, 5, brr, 5);
    printArray(arr,10);
}