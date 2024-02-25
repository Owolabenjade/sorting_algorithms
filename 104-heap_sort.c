#include "sort.h"

void swap(int *a, int *b);
void heapify(int *array, size_t size, int i, size_t actual_size);
void build_max_heap(int *array, size_t size);

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	/*Build a max heap from the array*/
	build_max_heap(array, size);

	for (int i = size - 1; i > 0; i--)
	{
		/*Swap the root of the heap with the last element*/
		swap(&array[0], &array[i]);
		print_array(array, size);
		/*Sift down the new root to maintain the max heap property*/
		heapify(array, i, 0, size);
	}
}

/**
 * build_max_heap - Builds a max heap from an unsorted array.
 * @array: The array to be turned into a max heap.
 * @size: The size of the array.
 */
void build_max_heap(int *array, size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
}

/**
 * heapify - Ensures the sub-tree rooted at element i
 * obeys the max heap property.
 * @array: The array representation of the heap.
 * @size: The size of the heap.
 * @i: The index of the root element of the sub-tree.
 * @actual_size: The actual size of the array for printing purposes.
 */
void heapify(int *array, size_t size, int i, size_t actual_size)
{
	int largest = i; /*Initialize largest as root*/
	int left = 2 * i + 1; /*left = 2*i + 1*/
	int right = 2 * i + 2; /*right = 2*i + 2*/

	/*If left child is larger than root*
	if (left < size && array[left] > array[largest])
		largest = left;

	/*If right child is larger than largest so far*/
	if (right < size && array[right] > array[largest])
		largest = right;

	/*If largest is not root*/
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, actual_size);
		/*Recursively heapify the affected sub-tree*/
		heapify(array, size, largest, actual_size);
	}
}

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
