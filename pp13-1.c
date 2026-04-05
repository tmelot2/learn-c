// Smallest & largest word

#include <stdio.h>
#include <string.h>

int main(void) {
	int lastLen = 0;
	char str[200];
	char smallest[200] = "";
	char largest[200] = "";

	while (lastLen != 4) {
		printf("Enter a word: ");
		scanf("%s", str);

		int length = strlen(str);
		if (length == 0) {
			continue;
		}

		if (strcmp(smallest, "") == 0) {
			strcpy(smallest, str);
			printf("start Smallest = %s\n", smallest);
		}
		if (strcmp(largest, "") == 0) {
			strcpy(largest, str);
			printf("start Largest = %s\n", largest);
		}

		if (strcmp(str, smallest) < 0) {
			strcpy(smallest, str);
		} else if (strcmp(str, largest) > 0) {
			strcpy(largest, str);
		}

		lastLen = strlen(str);
	}

	printf("Smallest: %s\n", smallest);
	printf("Largest: %s\n", largest);

	return 0;
}
