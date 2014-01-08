#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t *shellsort(int32_t *, uint32_t);

int main(void)
{
    int i = 0;

    int arr[10] = {15, 91, 13, 32, 21, 12, 17, 23, 10, 11};

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    shellsort(arr, 10);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}

int32_t *shellsort(int32_t *arr, uint32_t size)
{
    uint32_t step, i, j, k, z;
    int32_t tmp;

    j = 0;
    step = 0;

    while(step <= size)
    {
        j++;
        step = 3 * j - 1;
    }


    while(step)
    {
        for(i = 0; i < step; i++)
        {
            for(k = i + step; k < size; k += step)
            {
                z = k;
                while( (z >= 0) && (arr[z] > arr[z + step]) )
                {
                    tmp = arr[z];
                    arr[z] = arr[z + step];
                    arr[z + step] = arr[z];
                }
            }
        }

        j--;
        step = 3 * j - 1;
    }

    return arr;
}
