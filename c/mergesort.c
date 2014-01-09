#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "testsort.h"

int32_t *mergesort(int32_t *, uint32_t);

int main(void)
{
    int32_t *arr;

    arr = generate_array(ARR_SIZE);
    print_array(arr, ARR_SIZE);
    arr = mergesort(arr, ARR_SIZE);
    check_sorting(arr, ARR_SIZE);

    return EXIT_SUCCESS;
}

int32_t *mergesort(int32_t *arr, uint32_t arr_size)
{
    uint32_t size_sub_arr1, size_sub_arr2, middle, i, j;
    int32_t *sub_arr1, *sub_arr2, *k, *arr_res;

    if(arr_size < 2)
    {
        return arr;
    }

    middle = arr_size / 2;
    size_sub_arr1 = middle;
    size_sub_arr2 = arr_size - middle;
    sub_arr1 = mergesort(arr, size_sub_arr1);
    sub_arr2 = mergesort(&arr[size_sub_arr1], size_sub_arr2);
    arr_res = malloc(sizeof(int32_t) * (size_sub_arr1 + size_sub_arr2));

    if(arr_res == NULL)
    {
        printf("Can't allocate memory!\n");
        exit(0);
    }

    i = 0;
    j = 0;
    k = arr_res;

    for(i = 0; i < size_sub_arr1; i++)
    {
        while( (j < size_sub_arr2) && (sub_arr1[i] > sub_arr2[j]) )
        {
            *k = sub_arr2[j];
            k++;
            j++;
        }

        *k = sub_arr1[i];
        k++;
    }

    while(j < size_sub_arr2)
    {
            *k = sub_arr2[j];
            k++;
            j++;
    }
    
    if(size_sub_arr1 > 1)
    {
        free(sub_arr1);
        sub_arr1 = NULL;
    }

    if(size_sub_arr2 > 1)
    {
        free(sub_arr2);
        sub_arr2 = NULL;
    }
    return arr_res;
}
