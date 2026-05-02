// Exploring concepts from https://developer.ibm.com/articles/pa-dalign/

#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void munge8(void *data, uint32_t size) {
	uint8_t *data8 = (uint8_t *) data;
	uint8_t *data8End = data8 + size;

	while (data8 != data8End) {
		uint8_t temp = *data8;
		*data8++ = -temp;
	}
}

void munge16(void *data, uint32_t size) {
	uint16_t *data16 = (uint16_t *) data;
	uint16_t *data16End = data16 + (size >> 1); // Divide size by 2
	uint8_t *data8 = (uint8_t *) data16End;
	uint8_t *data8End = data8 + (size & 0x00000001); // Strip upper 31 bits.

	while (data16 != data16End) {
		uint16_t temp = *data16;
		*data16++ = -temp;
	}
	// Finish leftover byte, if needed.
	while (data8 != data8End) {
		uint8_t temp = *data8;
		*data8++ = -temp;
	}
}

void munge32(void *data, uint32_t size) {
	uint32_t *data32 = (uint32_t *) data;
	uint32_t *data32End = data32 + (size >> 2); // Divide size by 4.
	uint8_t *data8 = (uint8_t *) data32End;
	uint8_t *data8End = data8 + (size & 0x00000003); // Strip upper 30 bits.

	while (data32 != data32End) {
		uint32_t temp = *data32;
		*data32++ = -temp;
	}
	// Finish leftover byte, if needed.
	while (data8 != data8End) {
		uint8_t temp = *data8;
		*data8++ = -temp;
	}
}

void munge64(void *data, uint32_t size) {
	uint64_t *data64 = (uint64_t *) data;
	uint64_t *data64End = data64 + (size >> 3); // Divide size by 8.
	uint8_t *data8 = (uint8_t *) data64End;
	uint8_t *data8End = data8 + (size & 0x00000007); // Strip upper 29 bits.

	while (data64 != data64End) {
		uint64_t temp = *data64;
		*data64++ = -temp;
	}
	// Finish leftover byte, if needed.
	while (data8 != data8End) {
		uint8_t temp = *data8;
		*data8++ = -temp;
	}
}

uint64_t ts_to_ns(struct timespec t) {
    return ((uint64_t)t.tv_sec) * 1000000000ULL + (uint64_t)t.tv_nsec;
}

void run(char *name, int runs, void *ptr, uint32_t size, void (*fn)(void *, uint32_t)) {
	printf("Running %s\n", name);
	uint64_t total_ms = 0;
	// Warmup with some iterations so we're averaging warm run vs warm run.
	int warmup = 5;
	for (int i = 0; i < runs+warmup; i++) {
		struct timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		fn(ptr, size);
		clock_gettime(CLOCK_MONOTONIC, &end);

		if (i >= warmup) {
			uint64_t ns = ts_to_ns(end) - ts_to_ns(start);
			uint64_t ms = ns / 1000000ULL;
			total_ms += ms;
			printf("Run %d: %" PRIu64 " ms\n", (i-warmup)+1, ms);
		}
	}
	printf("Avg: %.1f ms\n\n", (double)total_ms/runs);
}

typedef struct {
	char a;
	long b;
	char c;
} Struct1;

int main(int argc, char *argv[]) {
	int runs = 1;
	if (argc == 2) {
		runs = atoi(argv[1]);
	}

	// Setup
	uint32_t size = 128 * 1024 * 1024;

	void *ptr = malloc(size);
	if (ptr == NULL) {
		printf("Could not allocate memory\n");
		return 0;
	}

	printf("sizeof   Struct1   = %zu\n", sizeof(Struct1));
	printf("offsetof Struct1 a = %zu\n", offsetof(Struct1, a));
	printf("offsetof Struct1 b = %zu\n", offsetof(Struct1, b));
	printf("offsetof Struct1 c = %zu\n", offsetof(Struct1, c));

	run("8-aligned", runs, ptr, size, munge8);
	run("8-unaligned", runs, ptr+1, size-1, munge8);
	run("16-aligned", runs, ptr, size, munge16);
	run("16-unaligned", runs, ptr+1, size-1, munge16);
	run("32-aligned", runs, ptr, size, munge32);
	run("32-unaligned", runs, ptr+1, size-1, munge32);
	run("64-aligned", runs, ptr, size, munge64);
	run("64-unaligned", runs, ptr+1, size-1, munge64);

	return 0;
}
