#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxMin(int a[], int n, int *max, int *min) {
	*max = *min = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] < *min) {
			*min = a[i];
		}

		if (a[i] > *max) {
			*max = a[i];
		}
	}
}

int main(void) {
	srand(time(NULL));
	int N = 10;
	int nums[N];
	for (int i = 0; i < N; i++) {
		nums[i] = i + rand() % 100;
	}

	int small, big;

	for (int i = 0; i < N; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	maxMin(nums, N, &big, &small);
	printf("%d %d\n", small, big);

	return 0;
}