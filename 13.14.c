#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool are_anagrams(char *s1, char *s2) {
	int seen[26] = {0};

	for (int i = 0; i < strlen(s1); i++) {
		int index = s1[i] - 'a';
		seen[index] += 1;
	}

	for (int i = 0; i < strlen(s1); i++) {
		int index = s2[i] - 'a';
		seen[index] -= 1;
	}

	int total = 0;
	for (int i = 0; i < 26; i++) {
		if (seen[i] > 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	char s1[50], s2[50];
	printf("Enter first word: ");
	fflush(stdout);
	scanf("%s", s1);
	printf("Enter second word: ");
	fflush(stdout);
	scanf("%s", s2);
	printf("\n");

	bool result = are_anagrams(s1, s2);
	if (result) {
		printf("ANAGRAM\n");
	} else {
		printf("NOT ANAGRAM\n");
	}


	return 0;
}
