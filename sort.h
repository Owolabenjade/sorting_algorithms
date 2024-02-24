#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Provided structure for doubly linked list */
typedef struct listint_s
{
        const int n;
        struct listint_s *prev;
        struct listint_s *next;
} listint_t;

/* Provided functions for printing array and list */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Function prototype for selection_sort */
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void print_list(const listint_t *list);

#endif /* SORT_H */
