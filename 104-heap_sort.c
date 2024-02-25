#include "sort.h"

/**
 * This function repairs the heap whose root element is at index 'start'
 * in an array 'array' of size 'size'. It assumes that the heaps rooted at
 * children of 'start' are already heapified.
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;
	int temp;

	while ((root * 2 + 1) <= end)
	{ /*While the root has at least one child*/
		child = root * 2 + 1; /*Left child*/
		swap = root; /*Keeps track of child to swap with*/

		if (array[swap] < array[child])
		{
			swap = child;
		}
		/*If there's a right child, and it is
		greater than what we're swapping with*/
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			swap = child + 1;
		}
		if (swap == root)
		{
			/*The root holds the largest element.
			Since we assume the heaps rooted at the
			children are valid, this means that we are done.*/
			break;
		} else
		{
			/*Swap the root with the greatest child*/
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size); /*Print the array after each swap*/

			/*Continue sifting down the child now*/
			root = swap;
		}
	}
}

/**
 * Builds a max heap from an unordered array.
 */
void buildMaxHeap(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2; /*Index of the last parent node*/

	while (start >= 0)
	{
		/*Sift down the node at index 'start' to
		the proper place such that all nodes below
		the start index are in heap order*/
		siftDown(array, start, size - 1, size);
		start--;
	}
}

/**
 * The main function that implements HeapSort.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	buildMaxHeap(array, size);

	end = size - 1;
	while (end > 0)
	{
		/*Swap the maximum value of the heap
		with the last element of the heap*/
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size); /*Print the array after each swap*/

		/*Put the heap back in max-heap order*/
		siftDown(array, 0, end - 1, size);
		end--;
	}
}
