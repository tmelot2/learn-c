#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
	*twenties = dollars / 20;
		dollars -= 20 * *twenties;

	*tens = dollars / 10;
		dollars -= 10 * *tens;

	*fives = dollars / 5;
	dollars -= 5 * *fives;

	*ones = dollars;
}

int main(void) {
	int dollars=0, twenties=0, tens=0, fives=0, ones=0;
	printf("Enter dollar amount: ");
	scanf("%d", &dollars);
	pay_amount(dollars, &twenties, &tens, &fives, &ones);
	printf("%d twenties, %d tens, %d fives, %d ones\n", twenties, tens, fives, ones);
	return 0;
}
