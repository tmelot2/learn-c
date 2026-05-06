#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2','3','4','5','6','7','8',
                            '9','t','j','q','k','a'};
  const char *rank_str[] = {
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "jack",
    "queen",
    "king",
    "ace"
  };
  const char suit_code[] = {'c','d','h','s'};
  const char *suit_str[] = {"clubs", "diamonds", "hearts", "spades"};

  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  fflush(stdout);
  scanf("%d", &num_cards);

  printf("Your hand:\n");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;     /* picks a random suit */
    rank = rand() % NUM_RANKS;     /* picks a random rank */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %s of %s (%c%c)\n", rank_str[rank], suit_str[suit], rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return 0;
}