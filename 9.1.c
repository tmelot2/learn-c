#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void selection_sort(int n, int arr[n]) {
	if (n < 0) {
		return;
	}

	int max_i = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[max_i]) {
			max_i = i;
		}
	}
	// Save last element (will be swapped).
	int temp = arr[n-1];
	// Move largest element to last element.
	arr[n-1] = arr[max_i];
	// Move prior last element to earlier in list.
	arr[max_i] = temp;
	selection_sort(n-1, arr);

}

int main(void) {
	// int arr[100] = {0};
	int arr[20] = {5, 19, 3, 5, 3, 6, 85, 4 , 32 ,7,33, 99, 1, 64, 32, 16};

	printf("Enter ints: ");
	printf("\n");
	int n;
	int count = 0;
	// while (scanf("%d", &n) == 1) {
	// 	printf("%d\n", n);
	// 	arr[count] = n;
	// }

	selection_sort(20, arr);
	printf("\n");

	for (int i = 0; i < 20; i++) {
		printf("%2d ", arr[i]);
	}

	return 0;
}
