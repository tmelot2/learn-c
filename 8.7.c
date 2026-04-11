#include <stdbool.h>   /* C99 only */
#include <stdio.h>

// Enter row 1: 8  3 9 0 10
// Enter row 2: 3 5 17 1 1
// Enter row 3: 2 8 6 23 1
// Enter row 4: 15 7 3 2 9
// Enter row 5: 6 14 2 6 0
// 8 3 9 0 10 3 5 17 1 1 2 8 6 23 1 15 7 3 2 9 6 14 2 6 0

int main(void)
{
	int rows = 5;
	int n[5][5] = {};
	for (int i = 0; i < rows; i++) {
		printf("Enter row %d: ", i+1);
		scanf("%d %d %d %d %d", &n[i][0], &n[i][1], &n[i][2], &n[i][3], &n[i][4]);
	}

	printf("\nRow total: ");
	for (int i = 0; i < rows; i++) {
		int row_total = 0;
		for (int j = 0; j < 5; j++) {
			row_total += n[i][j];
		}
		printf("%d ", row_total);
	}
	printf("\n");

	int col_total[5] = {0};
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 5; j++) {
			col_total[j] += n[i][j];
		}
	}
	printf("Col total: ");
	for (int i = 0; i < rows; i++) {
		printf("%d ", col_total[i]);
	}
	printf("\n");

	return 0;
}
