#include <stdio.h>
#include <string.h>

int main(void) {
	int seen[26] = {0};
	char s1[50], s2[50];
	printf("Enter first word: ");
	scanf("%s", s1);
	printf("Enter second word: ");
	scanf("%s", s2);
	printf("\n");

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
			printf("NOT A ANAGRAM\n");
			return 0;
		}
	}
	printf("IS A ANAGRAM\n");

	return 0;
}
