#include <stdint.h>
#include <stdio.h>

int main(void) {
	printf("int      %zu\n", sizeof(int));
	printf("uint8_t  %zu\n", sizeof(uint8_t));
	printf("uint16_t %zu\n", sizeof(uint16_t));
	printf("uint32_t %zu\n", sizeof(uint32_t));
	printf("uint64_t %zu\n", sizeof(uint64_t));
	printf("\n");

	printf("float       %zu\n", sizeof(float));
	printf("double      %zu\n", sizeof(double));
	printf("long double %zu\n", sizeof(long double));
	return 0;
}