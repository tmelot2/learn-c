#include <stdio.h>
#include <string.h>

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
	int MAX_LEN = 20;
	int len = 0;
	char word[MAX_LEN];
	char smallest[MAX_LEN];
	char largest[MAX_LEN];

	smallest[0] = '\0';
	largest[0] = '\0';

	do {
		printf("Enter a word: ");
		fflush(stdout);
		len = read_line(word, MAX_LEN);

		if ((strlen(smallest) == 0) || (strcmp(word, smallest) < 0)) {
			strcpy(smallest, word);
		}

		if ((strlen(largest) == 0) | (strcmp(word, largest) > 0)) {
			strcpy(largest, word);
		}

	} while (len != 4);

	printf("Smallest word: \"%s\"\n", smallest);
	printf("Largest word: \"%s\"\n", largest);

	return 0;
}