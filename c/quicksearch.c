#include <stdio.h>
#include <stdlib.h>

int quicksearch(int *, int, int);

int main(void)
{
    int ans = 0;
    int arr[10] = {1, 3, 6, 7, 11, 13, 14, 16, 19, 22};

    ans = quicksearch(arr, 10, 15);
    printf("answer: %d\n", ans);

    return EXIT_SUCCESS;
}

/*
 *n0<n1<n2 ...
 *
 */
int quicksearch(int *arr, int arr_size, int search)
{
    int low, middle, high;
    low = 0;
    high = arr_size - 1;

    while(low <= high)
    {
        middle = low + (high - low) / 2;

        if(arr[middle] < search)
        {
            low = middle +1;
        }
        else if(arr[middle] > search)
        {
            high = middle -1;
        }
        else
        {
            return middle;
        }
    }

    return 0;
}
