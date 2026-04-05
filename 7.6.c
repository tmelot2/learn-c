#include <stdio.h>

int main(void) {
	printf("short int\t%zd bytes (%lu bit)\n", sizeof(short int), sizeof(short int) * 8);
	printf("int\t\t%zd bytes (%lu bit)\n", sizeof(int), sizeof(int) * 8);
	printf("long int\t%zd bytes (%lu bit)\n", sizeof(long int), sizeof(long int) * 8);

	printf("\n");

	printf("float\t\t%zd bytes (%lu bit)\n", sizeof(float), sizeof(float) * 8);
	printf("double\t\t%zd bytes (%lu bit)\n", sizeof(double), sizeof(double) * 8);
	printf("long double\t%zd bytes (%lu bit)\n", sizeof(long double), sizeof(long double) * 8);

	return 0;
}