#include <stdio.h>

#define ARRAY_LEN(arr) sizeof(arr) / sizeof(arr[0])

void freqTest(int num) {
	int freq[10] = {0};

	int cur = num;
	int digit;
	while (cur > 0) {
		digit = cur % 10;
		printf("digit = %d\n", digit);
		freq[digit] += 1;
		cur = cur / 10;
	}

	printf("Repeated digits: ");
	for (int i = 0; i < ARRAY_LEN(freq); i++) {
		if (freq[i] > 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Digit frequency:\n");
	// Header
	for (int i = 0; i < ARRAY_LEN(freq); i++) {
		printf("%2d ", i);
	}
	printf("\n");
	// Data
	for (int i = 0; i < ARRAY_LEN(freq); i++) {
		printf("%2d ", freq[i]);
	}
	printf("\n\n");
}

int main(void) {
	int num = 1;

	while (num > 0) {
		printf("Enter num: ");
		fflush(stdout);
		scanf("%d", &num);
		freqTest(num);
	}

	return 0;
}