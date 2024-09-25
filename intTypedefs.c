#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int main(void) {
	typedef uint8_t u8;
	typedef uint16_t u16;
	typedef uint32_t u32;
	typedef uint64_t u64;

	u8  a = UINT8_MAX;
	u16 b = UINT16_MAX;
	u32 c = UINT32_MAX;
	u64 d = UINT64_MAX;

	printf("u8  a = %d,   size = %zu\n", a, sizeof(u8));
	printf("u16 b = %d,   size = %zu\n", b, sizeof(u16));
	printf("u32 c = %lld, size = %zu\n", c, sizeof(u32));
	printf("u64 d = %" PRIu64 " (or %llu), size = %zu\n", d, d, sizeof(u64));
	printf("\n");

	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(short) = %zu\n", sizeof(short));
	printf("sizeof(long) = %zu\n", sizeof(long));
	printf("sizeof(float) = %zu\n", sizeof(float));
	printf("sizeof(double) = %zu\n", sizeof(double));
	printf("sizeof(long double) = %zu\n", sizeof(long double));
	printf("\n");

	// PRIu64 uses string literal concat, like this:
	printf("string_" "literal_" "concat");

	return 0;
}
