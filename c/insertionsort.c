#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "testsort.h"

int32_t *insertionsort(int32_t *, uint32_t);

int main(void)
{
    int i = 0;
    int32_t *arr;

    arr = generate_array(ARR_SIZE);
    print_array(arr, ARR_SIZE);
    insertionsort(arr, ARR_SIZE);
    check_sorting(arr, ARR_SIZE);

    return EXIT_SUCCESS;
}

int32_t *insertionsort(int32_t *arr, uint32_t arr_size)
{
    uint32_t i, j;
    int32_t tmp;

    for(i = 1; i < arr_size; i++)
    {
        j = i;
        tmp = arr[j];

        while( j && (arr[j - 1] > tmp) )
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = tmp;
    }

    return arr;
}
