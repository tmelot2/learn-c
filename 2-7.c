#include <stdio.h>

void payWithBills(int amount) {
	int total = amount;
	int twenties = 0, tens = 0, fives = 0, ones = 0;

	while (total > 0) {
		if (total >= 20) {
			twenties += 1;
			total -= 20;
		} else if (total >= 10) {
			tens += 1;
			total -= 10;
		} else if (total >= 5) {
			fives += 1;
			total -= 5;
		} else if (total >= 1) {
			ones += 1;
			total -= 1;
		}
	}
	printf("$20s: %d\n", twenties);
	printf("$10s: %d\n", tens);
	printf(" $5s: %d\n", fives);
	printf(" $1s: %d\n", ones);
}

int main(void) {
	int amount = 0;
	printf("Enter ammount (whole dollars, no cents): ");
	// fflush(stdout);
	// scanf("%d", &amount);
	amount = 99;
	payWithBills(amount);

	return 0;
}