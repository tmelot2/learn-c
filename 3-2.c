#include <stdio.h>

int main(void) {
	int itemNumber;
	float unitPrice;
	int month, day, year;

	// Item
	printf("Enter item number: ");
	fflush(stdout);
	// itemNumber = 583;
	scanf("%d", &itemNumber);

	// Unit price
	printf("Enter unit price: ");
	fflush(stdout);
	// unitPrice = 13.50;
	scanf("%f", &unitPrice);

	// Purchase date
	printf("Enter date (mm/dd/yyyy): ");
	fflush(stdout);
	// month = 10;
	// day = 19;
	// year = 1982;
	scanf("%d/%d/%d", &month, &day, &year);

	// printf("Formatted date: %d%d%d\n", year, month, day);
	printf("\n");
	printf("Item		Unit		Purchase\n");
	printf("		Price		Date\n");
	printf("%-d		$%7.2f	%d/%d/%d\n", itemNumber, unitPrice, month, day, year);

	return 0;
}
