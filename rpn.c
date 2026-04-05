#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char stack[200][256];
	int num = 0;

	for (int i = 0; i < argc && i < 200; i++) {
		strncpy(stack[i], argv[i], 255);
	}
	for(int i = 0; i < argc; i++) {
		printf("%s\n", stack[i]);
	}
	return 0;
}