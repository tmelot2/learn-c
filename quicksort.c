#include <stdio.h>

#define N 10

int split(int a[], int low, int high) {
	int partition = a[low];

	for (;;) {
		while (low < high && partition <= a[high]) {
			high--;
		}
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= partition) {
			low++;
		}
		if (low >= high) break;
		a[high--] = a[low];
	}

	a[high] = partition;
	return high;
}

void quicksort(int a[], int low, int high) {
	int middle;

	if (low >= high) return;
	middle = split(a, low, high);
	quicksort(a, low, middle-1);
	quicksort(a, middle + 1, high);
}

int main(void) {
	int a[N] = {12, 3, 6, 18, 7, 15, 10};
	int i;

	// printf("Enter %d numbers to be sorted: ", N);
	// fflush(stdout);
	// for (i = 0; i < N; i++) {
	// 	scanf("%d", &a[i]);
	// }

	quicksort(a, 0, N-1);

	printf("In sorted order: ");
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
