#include <stdio.h>

#define INCHES_PER_POUND 166

int main(void) {
	int height, length, width, volume, weight;

	printf("Enter height: ");
	fflush(stdout);
	scanf("%d", &height);
	printf("Enter length: ");
	fflush(stdout);
	scanf("%d", &length);
	printf("Enter width: ");
	fflush(stdout);
	scanf("%d", &width);

	volume = height * length * width;
	weight = (volume + INCHES_PER_POUND-1) / INCHES_PER_POUND;

	printf("Volume: %d\n", volume);
	printf("Dimensional weight: %d\n", weight);

	return 0;
}