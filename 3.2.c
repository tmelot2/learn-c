#include <stdio.h>

int main(void) {
	int itemNumber;
	float price;
	int month, day, year;

	printf("Enter item number: ");
	scanf("%d", &itemNumber);

	printf("Enter price: ");
	scanf("%f", &price);

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Item\tUnit\tPurchase\n");
	printf("\tPrice\tDate\n");
	printf("%d\t$%6.2f\t%d/%d/%d\n", itemNumber, price, month, day, year);
	return 0;
}