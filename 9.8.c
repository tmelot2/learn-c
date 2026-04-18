#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int game_num = 0;

int roll_dice() {
	int n1 = (rand() % 6) + 1;
	int n2 = (rand() % 6) + 1;
	printf("%d %d\n", n1, n2);
	return n1 + n2;
}

bool play_game() {
	int point = 0;
	int sum = roll_dice();
	printf("You rolled %d\n", sum);
	if (game_num == 0) {
		if (sum == 7 || sum == 11) {
			return true;
		} else if (sum == 2 || sum == 3 || sum == 12) {
			return false;
		} else {
			point = sum;
			printf("Point is %d\n", point);
		}
	}
	sum = roll_dice();
	printf("You rolled %d\n", sum);

	while (sum != 7 && sum != point) {
		sum = roll_dice();
		printf("You rolled %d\n", sum);
	}

	if (sum == 7) {
		return false;
	} else if (sum == point) {
		return true;
	}
}

int main(void) {
	srand(time(NULL));

	int wins = 0, losses = 0;
	bool play_again = true;
	char ch;

	while (play_again) {
		bool won = play_game();
		if (won) {
			printf("You won!\n");
			wins += 1;
		} else {
			printf("You lost!\n");
			losses += 1;
		}
		printf("Play again? ");
		scanf(" %c", &ch);
		printf("\n");
		play_again = (ch == 'y') ? true : false;
	}

	printf("\nWins: %d  Losses: %d\n", wins, losses);

	return 0;
}