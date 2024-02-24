#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in
 * ascending order using the Shell sort
 * algorithm (Knuth sequence)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/*Calculate initial gap using Knuth's sequence*/
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	/*Start with the largest gap and work down to a gap of 1*/
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		/*Print the array after each interval decrease*/
		print_array(array, size);

		/*Decrease gap for next stage*/
		gap = (gap - 1) / 3;
	}
}
