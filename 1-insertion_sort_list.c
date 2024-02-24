#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *next_node;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = current;

			print_list(*list);
		}

		current = next_node;
	}
}
