#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
bool playGame(void);

int main(void) {
	srand(time(0));

	int totalWins = 0;
	int totalLosses = 0;

	char input;
	bool playAgain = true;
	while (playAgain) {
		bool win = playGame();
		if (win) {
			totalWins += 1;
			printf("A WINNER IS UUUUUUUUUUUUUUUUUUUUUU\n");
		} else {
			totalLosses += 1;
			printf("(Street Fighter 2 announcer voice): YOU. LOSE.\n");
		}

		printf("Play again? [y/n] ");
		fflush(stdout);
		scanf(" %c", &input);
		if (input == 'y') {
			playAgain = true;
		} else {
			playAgain = false;
		}

		printf("\n");

	}

	printf("Total wins:   %2d\n", totalWins);
	printf("Total losses: %2d\n", totalLosses);

	return 0;
}


int rollDice(void) {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}

bool playGame(void) {
	bool win = false;
	bool firstRoll = true;
	int point = 0;

	while (true) {
		int sum = rollDice();
		printf("You rolled %d", sum);

		if (firstRoll) {
			point = sum;
			printf(", point is %d\n", point);

			// Win!
			if (sum == 7 || sum == 11) {
				win = true;
				break;
			}
			// Lose =(
			if (sum == 2 || sum == 3 || sum == 12) {
				win = false;
				break;
			}

			firstRoll = false;
		} else {
			printf("\n");
			// Win!
			if (sum == point) {
				win = true;
				break;
			}

			// Lose =(
			if (sum == 7) {
				win = false;
				break;
			}
		}
	}

	return win;
}
