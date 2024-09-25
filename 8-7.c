#include <stdio.h>
#include <string.h>

#define N 5

// memcpy(dest, src, size_t)

// 1 2 3 4 5

int main(void) {
	int nums[N][N] = {0};

	for (int i = 0; i < N; i++) {
		printf("Enter row %d: ", i+1);
		fflush(stdout);

		// Read input in a loop
		int row[N] = {0};
		// printf("\n");
		for (int j = 0; j < N; j++) {
			scanf("%d", &row[j]);
			// row[j] = j+1;
		}

		// Copy row into matrix
		memcpy(nums[i], row, sizeof(row));
	}

	// Sum rows
	printf("Row totals: ");
	for (int i = 0; i < N; i++) {
		int total = 0;
		for (int j = 0; j < N; j++) {
			total += nums[i][j];
		}
		printf("%3d ", total);
	}
	printf("\n");

	// Sum cols
	printf("Col totals: ");
	int colTotals[N] = {0};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			colTotals[j] += nums[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%3d ", colTotals[i]);
	}

	return 0;
}
