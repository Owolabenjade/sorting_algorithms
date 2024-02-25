#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * Merge two subarrays L and R into arr.
 * @param array The original array to be sorted.
 * @param left The left sub-array.
 * @param left_count The number of elements in the left sub-array.
 * @param right The right sub-array.
 * @param right_count The number of elements in the right sub-array.
 */
void merge(int *array, int *left, int left_count, int *right, int right_count)
{
	int i = 0, j = 0, k = 0;

	/*Merge the temp arrays back into array[l..r]*/
	while (i < left_count && j < right_count)
	{
		if (left[i] <= right[j]) {
			array[k++] = left[i++];
		} else {
			array[k++] = right[j++];
		}
	}

	/*Copy the remaining elements of left[], if there are any*/
	while (i < left_count)
	{
		array[k++] = left[i++];
	}

	/*Copy the remaining elements of right[], if there are any*/
	while (j < right_count)
	{
		array[k++] = right[j++];
	}
}

/**
 * Main function that sorts arr[l..r] using merge().
 * @param array The array to be sorted.
 * @param n The number of elements in the array.
 */
void merge_sort_rec(int *array, int n)
{
	int mid, i, *left, *right;
	if (n < 2) return; /*Base condition: if array size is 1, return*/
	/*Find the midpoint to divide the array into two halves*/
	mid = n / 2;

	/*Dynamically allocate memory for the subarrays*/
	left = (int*)malloc(mid * sizeof(int)); 
	right = (int*)malloc((n - mid) * sizeof(int));

	/*Copy the data to the temporary subarrays left[] and right[]*/
	for (i = 0; i < mid; i++) left[i] = array[i];
	for (i = mid; i < n; i++) right[i - mid] = array[i];

	/*Sort the two halves of the array*/
	merge_sort_rec(left, mid);
	merge_sort_rec(right, n - mid);

	/*Merge the sorted halves*/
	merge(array, left, mid, right, n - mid);

	/*Free the dynamically allocated memory*/
	free(left);
	free(right);
}

/**
 * The public interface for the Merge Sort function.
 * This function kicks off the recursive merge sort process.
 * @param array The array to be sorted.
 * @param size The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_rec(array, size);
}
