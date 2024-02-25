#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, *count, *output, i;

	if (!array || size < 2)
		return;

	/*Step 1: Find the maximum value in the array*/
	for (i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	/*Step 2: Create and initialize the counting array*/
	count = malloc((k + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;

	/*Step 3: Store the count of each element*/
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/*Print the counting array*/
	print_array(count, k + 1);

	/*Step 5: Change count[i] so it contains the actual position*/
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	/*Step 6: Build the output array*/
	output = malloc(size * sizeof(int));
	if (!output) {
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/*Step 7: Copy the output array to the original array*/
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
