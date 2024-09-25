#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
	char suits[NUM_SUITS] = {'h', 'd', 's', 'c'};
	char cards[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

	bool inHand[NUM_SUITS][NUM_RANKS] = {0};
	int count = 0;

	// Seed rng
	srand((unsigned) time (NULL));

	// Input card count
	printf("Deal how many cards? ");
	fflush(stdout);
	scanf("%d", &count);
	int maxCards = NUM_SUITS * NUM_RANKS;
	if (count > maxCards) {
		printf("Too many cards, capping at %d\n", maxCards);
		count = maxCards;
	}

	// Deal cards
	while (count > 0) {
		int suit = rand() % NUM_SUITS;
		int card = rand() % NUM_RANKS;

		if (inHand[suit][card] == 1) {
			printf("Already picked %c%c, choosing another!\n", cards[card], suits[suit]);
		} else {
			inHand[suit][card] = 1;
			count -= 1;
		}
	}

	// Print hand
	for (int s = 0; s < NUM_SUITS; s++) {
		for (int c = 0; c < NUM_RANKS; c++) {
			if (inHand[s][c] == 1) {
				printf("%c%c ", cards[c], suits[s]);
			}
		}
	}

	printf("\n");

	return 0;
}