#include <stdio.h>
#include <string.h>

int main(void) {
	printf("Enter phone number: ");
	// 1-800-ABCDEFG
	char ch;
	char number[16];
	int count = 0;
	while ((ch = getchar()) != '\n') {
		if (ch == 'A' || ch == 'B' || ch == 'C') {
			ch = '2';
		} else if (ch == 'D' || ch == 'E' || ch == 'F') {
			ch = '3';
		} else if (ch == 'G' || ch == 'H' || ch == 'I') {
			ch = '4';
		} else if (ch == 'J' || ch == 'K' || ch == 'L') {
			ch = '5';
		} else if (ch == 'M' || ch == 'N' || ch == 'O') {
			ch = '6';
		} else if (ch == 'P' || ch == 'R' || ch == 'S') {
			ch = '7';
		} else if (ch == 'T' || ch == 'U' || ch == 'V') {
			ch = '8';
		} else if (ch == 'W' || ch == 'X' || ch == 'Y') {
			ch = '3';
		} else {

		}
		number[count++] = ch;
	}

	// for (int i = 0; i < strlen(number); i++) {
	// 	ch = number[i];
	// }

	printf("%s\n", number);
	return 0;
}