#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t *mergesort(int32_t *, uint32_t);

int main(void)
{
    int i = 0;
    int32_t arr[10]  = {9, 3, 5, 11, 7, 4, 12, 15, 14, 10};
    int32_t *sorted_array;

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    sorted_array = mergesort(arr, 10);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}

int32_t *mergesort(int32_t *arr, uint32_t size)
{
    uint32_t size_sub_arr1, size_sub_arr2, middle, i, j;
    int32_t *sub_arr1, *sub_arr2, *k, *arr_res;

    if(size < 2)
    {
        return arr;
    }

    middle = size / 2;
    size_sub_arr1 = middle;
    size_sub_arr2 = size - middle;
    sub_arr1 = mergesort(arr, size_sub_arr1);
    sub_arr2 = mergesort(&arr[size_sub_arr1], size_sub_arr2);
    arr_res = (int32_t  *)malloc(sizeof(int32_t) + (size_sub_arr1 + size_sub_arr2));

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

    //не освобождается память!!!!
    /*free(arr1);*/
    /*free(arr2);*/

    return arr_res;
}
