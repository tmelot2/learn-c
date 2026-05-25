#include <stdio.h>

int main(void) {
	char *months[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	printf("Enter a date (mm/dd/yyyy): ");
	fflush(stdout);
	int m = 0;
	int d = 0;
	int y = 0;
	scanf("%2d/%2d/%4d", &m, &d, &y);
	printf("|m%d|d%d|y%d|\n", m, d, y);

	printf("You entered %s %d, %d\n", months[m-1], d, y);

	return 0;
}