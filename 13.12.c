#include <stdio.h>
#include <string.h>

// TODO: Store in 2d array
int main(void) {
	printf("Enter a sentence: ");
	char s[100];
	char terminator;
	char ch = getchar();
	int count = 0;
	while (ch != '!' && ch != '.' && ch != '?' && ch != '\n') {
		s[count++] = ch;
		ch = getchar();
	}
	if (ch != '\n') {
		terminator = ch;
	}

	// Iterate backwards.
	for (int i = count-1; i >= 0; i--) {
		// If found space or beginning of string, print this word.
		if (s[i] == ' ' || i == 0) {
			// Start to print from beginning of string or start of word (place we found space + 1)
			int j = (i == 0) ? 0 : i + 1;
			// Walk forwards until we hit space or end of string
			while (j < count && s[j] != ' ') {
				printf("%c", s[j]);
				j += 1;
			}
			if (i != 0) {
				printf(" ");
			}
		}
	}
	printf("%c\n", terminator);

	return 0;
}
