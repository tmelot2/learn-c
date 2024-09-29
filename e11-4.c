#include <stdio.h>

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

int main(void) {
	int a = 6;
	int b = 4;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}