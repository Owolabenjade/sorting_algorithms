#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumeration for the card suits
 * @SPADE: The spade suit
 * @HEART: The heart suit
 * @CLUB: The club suit
 * @DIAMOND: The diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 * @value: The value of the card (e.g., "Ace", "2", ..., "King")
 * @kind: The kind (suit) of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node structure for a doubly-linked list of cards
 * @card: A pointer to the card structure
 * @prev: A pointer to the previous node in the list
 * @next: A pointer to the next node in the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
