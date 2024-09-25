#include <stdio.h>

int main(void) {
	int month, day, year;

	printf("Enter date (mm/dd/yyyy): ");
	fflush(stdout);
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Formatted date: %d%d%d\n", year, month, day);

	return 0;
}
