#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "testsort.h"

int check_sorting(int32_t *arr, uint32_t arr_size)
{
    uint32_t i;

    for(i = 1; i < arr_size; i++)
    {
        if( arr[i - 1] > arr[i])
        {
            printf("Ugh! Array not sorted :(\n");
            print_array(arr, arr_size);
            exit(0);
        }
    }

    printf("Congratulation! Array sorted! :)\n");
    print_array(arr, arr_size);
    return 0;
}

void print_array(int32_t *arr, uint32_t arr_size)
{
    uint32_t i;

    for(i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    putc('\n', stdout);
}

int32_t *generate_array(uint32_t arr_size)
{
    uint32_t i;
    int32_t *arr;

    srand(time(NULL));
    
    arr = malloc(sizeof(int32_t) * arr_size);

    if(arr == NULL)
    {
        printf("Error! Can't allocate memory!\n");
        exit(0);
    }
    
    for(i = 0; i < arr_size; i++)
    {
        arr[i] = rand() % 100;
    }

    return arr;
}
