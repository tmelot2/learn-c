#include <stdio.h>
#include <stdbool.h>
#include <string.h>

float compute_tax(float income) {
	float base = 0.0;
	float percent = 0.0;
	float tax = 0.0;

	if (income <= 750.0) {
		tax = income * 0.01;
	} else if (income < 2250.0) {
		base = 7.50;
		tax = 0.02 * (income - 750.0);
	} else if (income < 3750.0) {
		base = 37.50;
		tax = 0.03 * (income - 2250.0);
	} else if (income < 5250) {
		base = 82.50;
		tax = 0.04 * (income - 3750.0);
	} else if (income < 7000) {
		base = 142.50;
		tax = 0.05 * (income - 5250.0);
	} else {
		base = 230.0;
		tax = 0.06 * (income - 7000);
	}
	return base + tax;
}

int main(void) {
	float income;
	printf("Enter income: ");
	scanf("%f", &income);
	float tax = compute_tax(income);
	printf("Tax = $%5.2f\n", tax);

	return 0;
}
