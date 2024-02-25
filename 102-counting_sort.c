#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int k = 0;
	for (size_t i = 0; i < size; i++)
		if (array[i] > k)
			k = array[i];

	int *count_array = malloc((k + 1) * sizeof(int));
	if (!count_array)
		return;

	for (int i = 0; i <= k; i++)
		count_array[i] = 0;

	for (size_t i = 0; i < size; i++)
		count_array[array[i]]++;

	/*Print the count_array*/
	for (int i = 0; i <= k; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count_array[i]);
	}
	printf("\n");

	for (int i = 1; i <= k; i++)
		count_array[i] += count_array[i - 1];

	int *output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count_array);
		return;
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(count_array);
	free(output);
}
