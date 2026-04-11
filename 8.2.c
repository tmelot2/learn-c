#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
	int digit_count[10] = {0};
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		digit_count[digit] += 1;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%3d ", i);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%3d ", digit_count[i]);
	}
	return 0;
}
