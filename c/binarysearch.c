#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

signed int binarysearch(int *, uint32_t, int32_t);

int main(void)
{
    int32_t position = 0;
    int arr[10] = {1, 3, 6, 7, 11, 13, 14, 16, 19, 22};

    position = binarysearch(arr, 10, 16);
    printf("answer: %d\n", position);

    return EXIT_SUCCESS;
}

/*
 *n0<n1<n2...
 */
signed int binarysearch(int *arr, uint32_t arr_size, int32_t search)
{
    //array is empty
    if(!arr_size)
    {
        return -1;
    }

    uint32_t low, middle, high;
    low = 0;
    high = arr_size - 1;

    while(low <= high)
    {
        middle = low + (high - low) / 2;

        if(arr[middle] < search)
        {
            low = middle +1;
        }
        else if(arr[middle] > search)
        {
            high = middle -1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}
