#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int *create_array(int n, int initial_value) {
	int *arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = initial_value;
	}
	return arr;
}

int main(void) {
	int *arr = create_array(10, 100);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}