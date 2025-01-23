while(j>=0 && !flag )
        {
            printArray(arr, 10);

            printf("i: %d, j: %d\n",i,j);
            if (arr[j]> brr[i])
            {
                arr[j + 1] = arr[j];
                arr[j] = brr[i];
                
            }
            else
            {
                flag = 1;
            }
            j--;
            
            
        }