// https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Arena {
	unsigned char *buf;
	size_t buf_len;
	size_t offset;
} Arena;

void *arena_alloc(struct Arena *a, size_t size) {
	// Check to see if there is enough space to allocate.
	printf("Arena length: %zu, offset %2.2f%%\n", a->buf_len, 100*(a->offset/(float)a->buf_len));
	if (a->offset + size <= a->buf_len) {
		void *ptr = a->buf + a->offset;
		a->offset += size;
		// Zero out memory.
		memset(ptr, 0, size);
		return ptr;
	}
	// Not enough memory, return null.
	return NULL;
}

void arena_free(struct Arena *a) {
	free(a->buf);
	a->buf = NULL;
	a->buf_len = 0;
	a->offset = 0;
}

int main(void) {
	size_t kb = 1 * 1024;
	size_t mb = kb * 1024;
	size_t gb = mb * 1024;

	// Init arena
	size_t arena_buffer_length = 1 * gb;
	unsigned char *arena_buffer = (unsigned char *) malloc(arena_buffer_length);
	if (arena_buffer == NULL) {
		printf("Error: Could not allocate arena memory.");
		return 0;
	}
	printf("Allocated %zu bytes\n", arena_buffer_length);
	struct Arena a = { .buf = arena_buffer, .buf_len = arena_buffer_length, .offset = 0 };

	// Run arena allocs
	for (int i = 0; i < 1025; i += 1) {
		size_t size_to_get = 1 * mb;
		char *ptr = arena_alloc(&a, size_to_get);
		if (ptr == NULL) {
			printf("Error: Arena out of memory.");
			break;
		}
		printf("Loop %d, got %zu bytes from arena\n", i+1, size_to_get);
	}

	printf("\n");
	printf("done");

	arena_free(&a);

	return 0;
}
