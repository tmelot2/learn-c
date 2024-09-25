#include <stdio.h>

int main(void) {
	int counter = 0;
	
	printf("Enter string: ");
	fflush(stdout);
	while (getchar() != '\n') {
		counter += 1;
	}

	printf("String is %d characters long\n", counter);

	return 0;
}
