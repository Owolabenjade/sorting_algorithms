#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - A utility function to get the maximum value in an array.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 * Return: The maximum element in the array.
 */
int getMax(int *array, size_t size)
{
	int mx = array[0];
	for (size_t i = 1; i < size; i++)
		if (array[i] > mx)
			mx = array[i];
	return mx;
}

/**
 * countingSort - A function to do counting sort of the array according to
 * the digit represented by exp.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 * @exp: The exponent representing the current digit to sort by.
 */
void countingSort(int *array, size_t size, int exp)
{
	int output[size]; /*Output array*/
	int i, count[10] = {0};

	/*Store count of occurrences in count[]*/
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/*Change count[i] so that count[i] now contains actual
	position of this digit in output[]*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*Build the output array*/
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/*Copy the output array to array[], so that array[] now
	contains sorted numbers according to current digit*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - The main function to that sorts arr[] of size n using Radix Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	/*Find the maximum number to know number of digits*/
	int m = getMax(array, size);

	/*Do counting sort for every digit. Note that instead
	of passing digit number, exp is passed. exp is 10^i
	where i is current digit number*/
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
