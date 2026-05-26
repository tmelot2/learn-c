#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *duplicate(char *s) {
	int len = strlen(s);
	char *new_s = malloc(len + 1);
	if (new_s == NULL) {
		return NULL;
	}
	for (int i = 0; i < len; i++) {
		new_s[i] = s[i];
	}
	new_s[len] = '\0';
	return new_s;
}

int main(void) {
	char *a = "haha";
	char *b = duplicate(a);
	printf("a=%s %zu b=%s %zu\n", a, strlen(a), b, strlen(b));
	return 0;
}