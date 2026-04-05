#include <stdio.h>

int main(void) {
	printf("Enter three numbers: ");
	int n;
	scanf("%d", &n);
	int ones = n % 100 % 10;
	int tens = n % 100 / 10;
	int hundreds = n / 100;
	printf("ones %d\n", ones);
	printf("tens %d\n", tens);
	printf("hundreds %d\n", hundreds);
	printf("Reversed: %d%d%d\n", ones, tens, hundreds);

	return 0;
}