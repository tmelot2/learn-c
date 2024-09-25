#include <stdio.h>

int main(void) {
	int N = 5;
	int a[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 100 * (i+1) * (j+1);
			printf("%12d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
