#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * getMax - A utility function to get the maximum value in an array
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Maximum integer in the array
 */
int getMax(int *array, int size)
{
	int mx = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > mx)
			mx = array[i];
	return mx;
}

/**
 * countingSort - A function to do counting sort of arr[] according to
 * the digit represented by exp.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: Exponent representing the significant digit
 */
void countingSort(int *array, int size, int exp)
{
	int output[size]; // output array
	int i, count[10] = {0};

	// Store count of occurrences in count[]
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = size - 1; i >= 0; i--) {
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	// Copy the output array to array[], so that array[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Main function to implement Radix Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	// Find the maximum number to know number of digits
	int m = getMax(array, size);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size); // Print after sorting by each digit
	}
}
