#include <stdio.h>
//#include <string.h>

int compute_vowel_count(const char *sentence) {
	int count = 0, i = 0;
	char ch;
	do {
		ch = sentence[i++];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
	} while (ch != '\0');
	return count;
}

int read_line(char s[], int n) {
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			s[i++] = ch;
		}
	}
	s[i] = '\0';
	return i;
}

int main(void) {
	char s[100];

	printf("Enter a sentence: ");
	read_line(s, 100);
	printf("|%s|\n", s);
	int vowel_count = compute_vowel_count(s);
	printf("Vowel count: %d\n", vowel_count);
	return 0;
}