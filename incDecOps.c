#include <stdio.h>

int main(void) {
	int i = 0;
	int j = 0;

	printf("i is %d, ++i is %d\n", i, ++i);
	printf(" i is %d\n", i);

	printf("j is %d, j++ is %d\n", j, j++);
	printf(" j is %d\n", j);

	return 0;
}
