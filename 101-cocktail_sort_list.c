#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The head of the doubly linked list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked
 * list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped != 0)
	{
		swapped = 0;
		node = *list;
		while (node->next != NULL)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				swapped = 1;
			}
			else
			{
				node = node->next;
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		node = node->prev;
		while (node->prev != NULL)
		{
			if (node->n < node->prev->n)
			{
				swap_nodes(list, node->prev, node);
				swapped = 1;
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
