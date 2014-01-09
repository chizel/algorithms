#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "testsort.h"

int32_t *selectionsort(int32_t *, uint32_t);

int main(void)
{
    int32_t *arr;

    arr = generate_array(ARR_SIZE);
    print_array(arr, ARR_SIZE);
    selectionsort(arr, ARR_SIZE);
    check_sorting(arr, ARR_SIZE);

    return EXIT_SUCCESS;
}

int32_t *selectionsort(int32_t *arr, uint32_t size)
{
    uint32_t min, i, j;
    int32_t tmp;

    for(i = 0; i < size - 1; i++)
    {
        min = i;
        j = i + 1;

        while(j < size)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }

            j++;
        }

        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

    return arr;
}
