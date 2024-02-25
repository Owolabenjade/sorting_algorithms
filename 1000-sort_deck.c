#include "deck.h"
#include <string.h>
#include <stdlib.h>

/**
 * card_value - Converts card value to an integer
 * @value: The value to convert
 * 
 * Return: The integer value of the card
 */
int card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0) return (1);
	if (strcmp(value, "Jack") == 0) return (11);
	if (strcmp(value, "Queen") == 0) return (12);
	if (strcmp(value, "King") == 0) return (13);
	return atoi(value);
}

/**
 * compare_cards - Compares two cards to determine their order
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * 
 * Return: Difference between the cards to determine their order
 */
int compare_cards(const void *a, const void *b)
{
	deck_node_t *cardA;
	deck_node_t *cardB;
	int valueA, valueB;
	int kindA, kindB;

	cardA = *(deck_node_t **)a;
	cardB = *(deck_node_t **)b;
	valueA = card_value(cardA->card->value);
	valueB = card_value(cardB->card->value);
	kindA = cardA->card->kind;
	kindB = cardB->card->kind;

	if (kindA != kindB) return kindA - kindB;
	return valueA - valueB;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the top of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp;
	deck_node_t **deck_array;
	int count, i;

	if (!deck || !*deck || !(*deck)->next) return;

	temp = *deck;
	count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}

	deck_array = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
	if (deck_array == NULL) return;

	temp = *deck;
	for (i = 0; i < count; i++) {
		deck_array[i] = temp;
		temp = temp->next;
	}

	qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count - 1; i++) {
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[0]->prev = NULL;
	deck_array[count - 1]->next = NULL;
	*deck = deck_array[0];

	free(deck_array);
}
