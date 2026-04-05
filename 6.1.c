#include <stdio.h>

int main(void) {
	float n = 0, max = 0;
	do {
		printf("Enter a number: ");
		scanf("%f", &n);
		if (n > max) {
			max = n;
		}
	} while (n != 0);
	printf("Max = %f\n", max);

	return 0;
}