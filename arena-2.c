#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct arena {
	int size;
	int cur;
	void *base;
} arena;

typedef struct guy {
	char *name;
	int hp;
} guy;

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

char *arena_strdup(arena *a, const char *s) {
	size_t len = strlen(s) + 1;
	char *copy = arena_alloc(a, len);

	if (copy == NULL) {
		return NULL;
	}

	memcpy(copy, s, len);
	return copy;
}

guy *guy_create(arena *a, const char *name, int hp) {
	guy *g = arena_alloc(a, sizeof(*g));

	if (g == NULL) {
		return NULL;
	}

	char *new_name = arena_strdup(a, name);
	if (name == NULL) {
		return NULL;
	}
	g->name = new_name;
	g->hp = hp;
	return g;
}

int main(void) {
	int bytes = 64;
	arena a = {
		.size = bytes,
		.cur = 0,
		.base = NULL
	};
	arena_init(&a);

	// char *n1 = "John Halo";
	// guy *enemy1 = arena_alloc(&a, sizeof(enemy1));
	// enemy1->name = arena_alloc(&a, strlen(n1)+1);
	guy_create(&a, "John Halo", 100);
	guy_create(&a, "Quasimorphosis Dude", 50);
	guy_create(&a, "Mike Diablo", 666);

	arena_free(&a);

	return 0;
}
