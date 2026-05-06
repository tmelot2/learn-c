#include <stdio.h>

int read_line(char str[], int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

int main(void) {
	int i = 50;
	char s[i];
	printf("Enter a line of text: ");
	read_line(s, i);
	printf("String = \"%s\"\n", s);
	return 0;
}