// https://igoro.com/archive/gallery-of-processor-cache-effects/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef uint64_t u64;

u64 ts_to_ns(struct timespec t) {
    return ((u64)t.tv_sec) * 1000000000ULL + (u64)t.tv_nsec;
}

u64 get_time_ms(struct timespec start, struct timespec end) {
	u64 ns = ts_to_ns(end) - ts_to_ns(start);
	u64 ms = ns / 1000000ULL;
	return ms;
}

void init_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

void run(int num, int arr_size, int step_size) {
	int *arr = malloc(arr_size * sizeof(int));
	init_arr(arr, arr_size);
	if (!arr) {
		printf("No memory\n");
		return;
	}

	// Run
	struct timespec start, end;
	for (int i = arr_size-1; i >= 0; i--) arr[i] = i;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < arr_size; i+=step_size) {
		arr[i] *= 2;
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("num=%2d step_size=%2d ms=%3llu\n", num, step_size, get_time_ms(start, end));
	free(arr);
}

int main(void) {
	// int array_size = 64;
	// int array_size = 64 * 1024;
	int array_size = 64 * 1024 * 1024;

	for (int i = 1; i <= 128; i++) {
		run(i, array_size, i);
	}

	return 0;
}