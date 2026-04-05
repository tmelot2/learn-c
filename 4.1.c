#include <stdio.h>

int main(void) {
	printf("Enter two numbers: ");
	int n;
	scanf("%d", &n);
	int ones = n % 10;
	int tens = (n - ones) / 10;
	printf("ones %d\n", ones);
	printf("tens %d\n", tens);
	printf("Reversed: %d%d\n", ones, tens);
	return 0;
}