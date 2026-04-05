#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool isAlpha(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return true;
	} else {
		return false;
	}
}

void capitalize(char str[]) {
	for (int i=0; i < strlen(str); i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
	}
}

void capitalizePointer(char *str) {
	char *ch = str;
	while (*ch != '\0') {
		if (*ch >= 97 && *ch <= 122) {
			*ch = *ch - 32;
		}
		ch += 1;
	}
}


int main(void) {
	char str[] = "Hello, world! 123";
	printf("Before: %s\n", str);
	// capitalize(str);
	capitalizePointer(str);
	printf("After: %s\n", str);


	return 0;
}