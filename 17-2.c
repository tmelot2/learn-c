#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *duplicate(char *str) {
	int length = strlen(str);
	char *new_str = malloc((length+1) * sizeof(char));

	for (int i = 0; i < strlen(str); i++) {
		new_str[i] = str[i];
	}
	new_str[length] = '\0';

	return new_str;
}

int main(void) {
	char str[] = "hello, world";
	char *new_str = duplicate(str);
	printf("%s\n", new_str);
	return 0;
}