#include <stdbool.h>
#include <stdio.h>

int len(char s[]) {
	int i = 0;
	char c = s[0];
	while (c != '\0') {
		i += 1;
		c = s[i];
	}
	return i;
}

int main(void) {
	bool isPalindrome = true;
	char message[] = "live on time emit no evil";
	int l = len(message);
	char *left = &message[0];
	char *right = &message[l-1];

	while (isPalindrome && left < right) {
		if (left == right) {
			break;
		}
		if (*left != *right) {
			isPalindrome = false;
			break;
		}
		left += 1;
		right -= 1;
	}

	printf("\"%s\"\n", message);
	if (isPalindrome) {
		printf("IS A PALINDROME!!!");
	} else {
		printf("IS NOT A PALINDROME!!!");
	}

	return 0;
}