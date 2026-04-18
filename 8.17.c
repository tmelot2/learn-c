#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
	int n;
	printf("Enter size of magic square: ");
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("Error: You must enter and odd number.\n");
		return 0;
	}

	int m[99][99] = {0};
	int ns = n * n;

	// Set row 0, middle col to 1.
	m[0][n/2] = 1;

	// Set remaining numbers to n^2.
	int cur_row = 0;
	int cur_col = n/2;
	for (int cur = 2; cur <= n * n; cur++) {
		int next_row = cur_row - 1;
		// Wrap from top to bottom.
		if (next_row < 0) {
			next_row = n - 1;
		}

		int next_col = cur_col + 1;
		// Wrap right to left.
		if (next_col >= n) {
			next_col = 0;
		}

		bool should_shift = (m[next_row][next_col] > 0);

		if (should_shift) {
		    next_row = (cur_row + 1) % n;   // drop down from CURRENT cell
		    next_col = cur_col;
		}

		// printf("storing %d, cur(%d,%d) next(%d,%d)\n", cur, cur_row, cur_col, next_row, next_col);
		printf("storing %d at next(%d,%d)\n", cur, next_row, next_col);
		m[next_row][next_col] = cur;
		cur_row = next_row;
		cur_col = next_col;
	}

	// Col headers
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("%4c %d ", ' ', i);
		} else {
			printf("%4d ", i);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				printf("%d ", i);
			}
			printf("%4d ", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}
