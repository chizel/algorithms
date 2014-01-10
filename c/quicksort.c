#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "testsort.h"

int32_t quicksort(int32_t *, uint32_t, uint32_t);

int main(void)
{
    int32_t *arr;

    arr = generate_array(ARR_SIZE);
    print_array(arr, ARR_SIZE);
    quicksort(arr, 0, ARR_SIZE - 1);
    check_sorting(arr, ARR_SIZE);

    return EXIT_SUCCESS;
}

int32_t quicksort(int32_t *arr, uint32_t low, uint32_t high)
{
    //array have one or less elements, nothing to sort
    if( (high - low) < 2)
    {
        return -1;
    }

    uint32_t middle, i, j;
    int32_t tmp, point;
    middle = low + (high - low) / 2;
    i = low + 1;
    j = high;
    point = arr[middle];

    while(i <= j)
    {
        while( (arr[i] < point) && (i <= j) )
        {
            i++;

            while( (arr[j] >= point) && (j > i) )
            {
                j--;
            }
        }


        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        i++;
        j--;
    }
            while( (arr[j] >= point) && (j > i) )
            {
                j--;
            }
printf("low: %d, high: %d, middle: %d\n", low, high, middle);
    /*if(arr[j] < arr[low])*/
    /*{*/
        /*tmp = arr[j];*/
        /*arr[j] = arr[low];*/
        /*arr[low] = tmp;*/
    /*}*/

for(i = low; i <= high; i++)
{
    printf("%d ", arr[i]);
}
printf("\n=================================\n");
/*if(middle==6)*/
/*exit(0);*/
        /*
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
    //*/

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
