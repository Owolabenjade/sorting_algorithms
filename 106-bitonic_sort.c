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
 * bitonic_compare - Helper function to compare and swap array elements.
 * @array: The array to sort.
 * @size: Number of elements in @array.
 * @start: Starting index of the sequence to merge.
 * @seq: Sequence size to compare.
 * @dir: Direction to sort, ASC (1) or DESC (0).
 */
void bitonic_compare(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t i, j;

	for (i = start; i < start + seq; i++)
	{
		j = i + seq;
		if (j < size && ((dir && array[i] > array[j]) || (!dir && array[i] < array[j])))
		{
			swap_ints(&array[i], &array[j]);
		}
	}
}

/**
 * bitonic_merge - Merges subsequences of an array in bitonic order.
 * @array: The array to sort.
 * @size: Number of elements in @array.
 * @start: Starting index of the sequence to merge.
 * @seq: Sequence size to merge.
 * @dir: Direction to sort, ASC (1) or DESC (0).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t k;

	if (seq > 1)
	{
		k = seq / 2;
		bitonic_compare(array, size, start, k, dir);
		bitonic_merge(array, size, start, k, dir);
		bitonic_merge(array, size, start + k, k, dir);
	}
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence.
 * @array: The array to sort.
 * @size: Number of elements in @array.
 * @start: Starting index of the sequence to sort.
 * @seq: Sequence size to sort.
 * @dir: Direction to sort, ASC (1) or DESC (0).
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t k;

	if (seq > 1)
	{
		k = seq / 2;
		/* Sort first half in ascending order */
		bitonic_sort_rec(array, size, start, k, 1);
		/* Sort second half in descending order */
		bitonic_sort_rec(array, size, start + k, k, 0);
		/* Merge the whole sequence */
		bitonic_merge(array, size, start, seq, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm.
 * @array: The array to sort.
 * @size: Number of elements in @array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}
