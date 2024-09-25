#include <stdio.h>

int main(void) {
	printf("Enter phone number (lowercase letters): ");
	fflush(stdout);

	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch == 'a' || ch == 'b' || ch == 'c') {
			putchar('2');
		} else if (ch == 'd' || ch == 'e' || ch == 'f') {
			putchar('3');
		} else if (ch == 'g' || ch == 'h' || ch == 'i') {
			putchar('4');
		} else if (ch == 'j' || ch == 'k' || ch == 'l') {
			putchar('5');
		} else if (ch == 'm' || ch == 'n' || ch == 'o') {
			putchar('6');
		} else if (ch == 'p' || ch == 'r' || ch == 's') {
			putchar('7');
		} else if (ch == 't' || ch == 'u' || ch == 'v') {
			putchar('8');
		} else if (ch == 'w' || ch == 'x' || ch == 'y') {
			putchar('9');
		} else {
			putchar(ch);
		}
	}

	return 0;
}
