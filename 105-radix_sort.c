#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * getMax - A utility function to get the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum integer in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
	}

/**
 * countSort - A function to do counting sort of array according to
 * the digit represented by exp (10^i).
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent of 10 to sort by
 */
void countSort(int *array, size_t size, int exp)
{
	int output[size]; // output array
	int i, count[10] = {0};

	/*Store count of occurrences in count[]*/
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/*Change count[i] so that count[i] now contains actual
	position of this digit in output[]*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*Build the output array*/
	for (i = size - 1; i >= 0; i--) {
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	// Copy the output array to array[], so that array[] now
	contains sorted numbers according to current digit*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Main function to sort array[] of size n using Radix Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	/*Find the maximum number to know number of digits*/
	int m = getMax(array, size);

	/*Do counting sort for every digit. Note that instead
	of passing digit number, exp is passed. exp is 10^i
	where i is current digit number */
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(array, size, exp);
		print_array(array, size);
	}
}
