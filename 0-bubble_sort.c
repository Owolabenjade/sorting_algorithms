#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print the array after each swap */
                print_array(array, size);
                swapped = 1;
            }
        }

        /* If no swaps occurred, the array is already sorted */
        if (!swapped)
            break;
    }
}
