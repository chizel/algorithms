#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int8_t quicksort(int *, uint32_t, uint32_t);

int main(void)
{
    uint32_t i;
    int arr[10] = {11, 10, 12, 13, 15, 14, 13, 16, 11, 12};

    quicksort(arr, 0, 9);

    for(i = 0; i <= 9; i++)
    {
        printf("%d ", arr[i]);
    } 

    putchar('\n');

    return EXIT_SUCCESS;
}

int8_t quicksort(int *arr, uint32_t low, uint32_t high)
{
    //array have one or less elements, nothing to sort
    if(high <= 1)
    {
        return -1;
    }

    uint32_t middle, i, j;
    int32_t tmp;
    middle = low + (high - low) / 2;
    i = low;
    j = high;

    for(i = 0; i < middle; i++)
    {
        if(arr[i] > arr[middle])
        {
            while(arr[j] > arr[middle])
            {
                j--;
            }

            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    if(low < middle)
    {
        quicksort(arr, low, middle - 1);
    }

    if(high > middle)
    {
        quicksort(arr, middle + 1, high);
    }

    return 0;
}
