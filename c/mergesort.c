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
/*
def mergesort(arr):
    size = len(arr)

    if size < 2:
        return arr

    middle = size / 2
    arr1 = mergesort(arr[0:middle])
    arr2 = mergesort(arr[middle:])
    i = 0
    arr_res = []

    for item in arr1:
        while(i < len(arr2)) and (arr2[i] < item):
            arr_res.append(arr2[i])
            i += 1
        arr_res.append(item)

    for j in range(i, len(arr2)):
        arr_res.append(arr2[j])
    return arr_res
*/

int32_t *mergesort(int32_t *arr, uint32_t size)
{
    uint32_t size_arr1, size_arr2, middle, i, j;
    int32_t *arr1, *arr2, *k, *arr_res;

    if(size < 2)
    {
        return arr;
    }

    middle = size / 2;
    size_arr1 = middle;
    size_arr2 = size - middle;
    arr1 = mergesort(arr, size_arr1);
    arr2 = mergesort(&arr[size_arr1], size_arr2);
    arr_res = (int32_t  *)malloc(sizeof(int32_t) + (size_arr1 + size_arr2));

    i = 0;
    j = 0;
    k = arr_res;

    for(i = 0; i < size_arr1; i++)
    {
        while( (j < size_arr2) && (arr1[i] > arr2[j]) )
        {
            *k = arr2[j];
            k++;
            j++;
        }

        *k = arr1[i];
        k++;
    }

    while(j < size_arr2)
    {
            *k = arr2[j];
            k++;
            j++;
    }

    /*free(arr1);*/
    /*free(arr2);*/

    return arr_res;
}
