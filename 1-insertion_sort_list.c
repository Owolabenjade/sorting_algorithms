#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using Insertion Sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap nodes */
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev->next = current->next;
            current->next = current->prev;
            current->prev = current->prev->prev;

            if (current->prev != NULL)
                current->prev->next = current;

            if (current->next == NULL)
                *list = current;

            print_list(*list);
        }

        current = temp;
    }
}
