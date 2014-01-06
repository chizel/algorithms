#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t *insertionsort(int32_t *, uint32_t);

int main(void)
{
    int i = 0;

    int arr[10] = {5, 9, 3, 2, 1, 12, 7, 3, 10, 11};

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    insertionsort(arr, 10);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}

int32_t *insertionsort(int32_t *arr, uint32_t size)
{
    uint32_t i, j;
    int32_t tmp;

    for(i = 1; i < size; i++)
    {
        j = i;
        tmp = arr[j];

        while( j && (arr[j -1] > tmp) )
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = tmp;
    }

    return arr;
}
