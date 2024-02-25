#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Orders a subset of an array of integers according to the Hoare
 *             partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(array + i, array + j);
		print_array(array, size);
	}
}

/**
 * quicksort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to sort.
 * @high: The ending index of the array partition to sort.
 */
void quicksort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, size, low, high);

		quicksort(array, size, low, pi);
		quicksort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick sort algorithm with the Hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
