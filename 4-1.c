#include <stdio.h>
#include <math.h>

int digitLen(int num) {
	int remainder = num;
	int length = 0;

	while (remainder > 0) {
		remainder /= 10;
		length += 1;
	}

	return length;
}

int reversed(int num) {
	int result = 0;
	int remainder = num;
	int i = 0;

	while (remainder > 0) {
		int digit = remainder % 10;
		remainder /= 10;
		result += pow(10, digitLen(num)-i-1) * digit;
		i += 1;
	}

	return result;
}

int main(void) {
	int num;

	printf("Enter a number to reverse: ");
	fflush(stdout);
	scanf("%d", &num);

	printf("result = %d\n", reversed(num));

	return 0;
}
