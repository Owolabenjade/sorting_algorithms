#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;  /*List is empty or has only one element*/
	}

	/*Start with the second node*/
	current = (*list)->next;

	while (current)
	{
		next = current->next;
		prev = NULL;

		/*Find the insertion position for the current node*/
		while (current->prev && current->n < current->prev->n)
		{
			prev = current->prev;
			current->prev = prev->next;
			if (prev->next) {
				prev->next->prev = current;
			}
			current->next = prev;
			prev->next = current;

			/*Print the list after each swap*/
			print_list(*list);
		}

		/*If the current node was at the beginning, update the head*/
		if (prev == NULL)
		{
			*list = current;
		}

		current = next;
	}
}
