#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t *selectionsort(int32_t *, uint32_t);

int main(void)
{
    int i = 0;

    int arr[10] = {15, 91, 13, 32, 21, 12, 17, 23, 10, 11};

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    selectionsort(arr, 10);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

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
