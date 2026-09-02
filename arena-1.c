#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct arena {
	int size;
	int cur;
	void *base;
} arena;

void arena_init(arena *a) {
	a->cur = 0;
	a->base = malloc(a->size * sizeof(char));
	printf("Arena initialized with %d bytes\n", a->size);
}

void *arena_alloc(arena *a, int size) {
	if (a->cur + size > a->size) {
		printf("Can't allocate %d bytes, not enough memory (used %d of %d bytes)\n", size, a->cur, a->size);
		return NULL;
	}

	void *cur = a->base + a->cur;
	memset(cur, 0, size);
	a->cur += size;
	printf("Returning %d bytes from arena (%d left)\n", size, a->size - a->cur);
	return cur;
}

void arena_reset(arena *a) {
	a->cur = 0;
}

void arena_free(arena *a) {
	free(a->base);
}

int main(void) {
	int bytes = 32;
	arena a = {
		.size = bytes,
		.cur = 0,
		.base = NULL
	};
	arena_init(&a);
	for (int i = 0; i < 5; i++) {
		uint64_t *data = arena_alloc(&a, sizeof(uint64_t));
		if (data != NULL) {
			printf("Got %d bytes at address %p = %d\n", sizeof(uint64_t), data, *data);
		}
	}

	arena_reset(&a);
	printf("\n");

	for (int i = 0; i < 5; i++) {
		arena_alloc(&a, 2);
	}

	arena_free(&a);

	return 0;
}
