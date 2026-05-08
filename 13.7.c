#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *tens_str[] = {
		"",
		"",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};
	char *ones_str[] = {
		"",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	int n = 0;
	char *result = calloc(100, sizeof(char));

	printf("Enter a two-digit number: ");
	scanf("%d", &n);

	if (n < 10 || n > 99) {
		printf("Incorrect number of digits\n");
		return 1;
	}

	int ones = n % 10;
	int tens = n / 10;

	// Teens
	if (tens == 1) {
		char *teens_str[] = {
			"ten",
			"eleven",
			"twelve",
			"thirteen",
			"fourteen",
			"fifteen",
			"sixteen",
			"seventeen",
			"eighteen",
			"nineteen"
		};
		strcat(result, teens_str[ones]);
	}
	// Everything else
	else {
		strcat(result, tens_str[tens]);
		strcat(result, " ");
		strcat(result, ones_str[ones]);
	}

	printf("You entered %s\n", result);

	return 0;
}