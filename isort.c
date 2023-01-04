#include "isort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief shifts the array 1 cell to the right starting from idx i
 * 
 * @param arr array to perform shift on
 * @param i index to begin shift from
 */
void shift_elements(int *arr, int i)
{
    int start = i;
    int prev = *arr, temp = *arr;
    int j = i + 1;
    while ((arr + j) != NULL && i < MAX_SIZE + 1)
    {
        temp = *(arr + j);
        *(arr + j) = prev;
        prev = temp;
        i++;
        j++;
    }
    *(arr + start) = 0; 
}

/**
 * @brief standard insertion sort
 * Worst case Time O(n^2)
 * @param arr array to sort
 * @param len the length of the array
 */
void insertion_sort(int *arr, int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

/**
 * @brief reads an array from stdin
 * 
 * @return int* the output array
 */
int *getArray()
{
    int *arr = malloc(MAX_SIZE + 1);
    int i = 0;
    while (scanf("%d", (arr + i)) == 1 && i < MAX_SIZE + 1)
        i++;
    return arr;
}

/**
 * @brief prints an array integers separated with commas
 * 
 * @param arr an array to print
 */
void print_arr(int *arr)
{
    int i = 0;
    while (i < MAX_SIZE)
    {
        printf("%d", *(arr + i));
        if (i != MAX_SIZE -1)
            printf(",");
        i++;
    }
    printf("\n");
}

int main(void)
{
    int *arr;
    printf("Please enter %d integers separated with spaces: \n", MAX_SIZE);
    arr = getArray();
    insertion_sort(arr, MAX_SIZE);
    print_arr(arr);
    return 0;
}
