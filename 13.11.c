#include <stdio.h>
#include <string.h>

double compute_avg_word_len(const char *sentence) {
	int num_words = 0;
	int num_chars = 0;
	int cur = 0;
	double avg = 0.0;

	for (int i = 0; i < strlen(sentence); i++) {
		char ch = sentence[i];
		if (ch != ' ') {
			cur += 1;
			num_chars += 1;
		} else {
			// End word, compute, reset
			cur = 0;
			num_words += 1;
		}
		printf("ch=%c cur=%d num_chars=%d num_words=%d\n", ch, cur, num_chars, num_words);
	}

	// Calc any remaining word
	if (cur > 0) {
		num_words += 1;
	}

	avg = (double) num_chars / num_words;

	return avg;
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
	printf("Enter a sentence: ");
	char s[100] = {'\0'};
	// Input: it was deja vu all over again.
	read_line(s, 100);
	double avg = compute_avg_word_len(s);
	printf("Average word length: %.2f\n", avg);
	return 0;
}
