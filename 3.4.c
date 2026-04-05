#include <stdio.h>

int main(void) {
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	int area, first, second;
	scanf("(%d) %d-%d", &area, &first, &second);
	printf("You entered %d.%d.%d\n", area, first, second);
	return 0;
}