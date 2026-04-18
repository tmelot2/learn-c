#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool equal_array(int counts1[26], int counts2[26]) {
	for (int i = 0; i < 26; i++) {
		if (counts1[i] != counts2[i]) {
			return false;
		}
	}
	return true;
}

void read_word(int counts[26]) {
	char s[50];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		int index = s[i] - 'a';
		counts[index] += 1;
	}
}

int main(void) {
	int counts1[26] = {0};
	int counts2[26] = {0};

	printf("Enter first word: ");
	read_word(counts1);
	printf("Enter second word: ");
	read_word(counts2);

	bool is_equal = equal_array(counts1, counts2);
	if (is_equal) {
		printf("IS ANAGRAM");
	} else {
		printf("IS NOT ANAGRAM");
	}

	return 0;
}
