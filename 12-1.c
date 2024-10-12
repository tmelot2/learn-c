#include <stdio.h>

// Max length
#define MAX_LENGTH 45

// A man's life is what his thoughts make of it.

char message[MAX_LENGTH];
char *messageTail;
int length = 0;

void input() {
	// Prompt
	printf("Enter a message (%d chars max): ", MAX_LENGTH);
	fflush(stdout);

	// Input
	char c = getchar();
	while (length < MAX_LENGTH && c != '\n') {
		message[length] = c;
		messageTail = &message[length];
		length += 1;
		c = getchar();
	}
}

void printReversedArray() {
	// Reverse
	printf("Reversed: ");
	for (int i = MAX_LENGTH-1; i >= 0; i--) {
		printf("%c", message[i]);
	}
}

void printReversedPointer() {
	// Reverse
	printf("Reversed: ");
	int curIndex = length;
	while (curIndex >= 0) {
		printf("%c", *messageTail);
		curIndex -= 1;
		messageTail -= 1;
	}
}

int main(void) {
	input();

	printReversedArray();
	printf("\n");

	printReversedPointer();
	printf("\n");

	return 0;
}