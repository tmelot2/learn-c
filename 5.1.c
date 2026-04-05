#include <stdio.h>

int main(void) {
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);
	if (n >= 0 && n <= 9) {
		printf("Num %d has 1 digit\n", n);
	} else if (n >= 10 && n <= 99) {
		printf("Num %d has 2 digits\n", n);
	} else if (n >= 100 && n <= 999) {
		printf("Num %d has 3 digits\n", n);
	}

	return 0;
}