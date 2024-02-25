#include "sort.h"

/**
 * Swap two elements in the array
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * Function to print the result after each swap
 */
void print_step(const int *array, size_t size, size_t start, size_t seq, int dir)
{
	printf("Result [%lu/%lu] (%s):\n", seq, size, dir ? "UP" : "DOWN");
	print_array(array + start, seq);
}

/**
 * Merge function for Bitonic sort
 */
void bitonic_merge(int *array, size_t size, size_t start, int dir)
{
	if (size < 2)
		return;
	size_t k = size / 2;
	for (size_t i = start; i < start + k; i++)
		if ((dir && array[i] > array[i + k]) || (!dir && array[i] < array[i + k])) {
			swap(&array[i], &array[i + k]);
			print_step(array, size, start, size, dir);
		}
	bitonic_merge(array, k, start, dir);
	bitonic_merge(array, k, start + k, dir);
}

/**
 * Recursive function to sort a bitonic sequence in ascending or descending order
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, int dir)
{
	if (size < 2)
		return;
	size_t k = size / 2;

	// Sort first half in ascending order, second half in descending order
	bitonic_sort_rec(array, k, start, 1);
	bitonic_sort_rec(array, k, start + k, 0);

	// Merge the entire sequence in ascending order
	bitonic_merge(array, size, start, dir);
}

/**
 * Main entry point for the Bitonic sort
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_rec(array, size, 0, 1);
}

/**
 * Utility function to print the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++) {
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
