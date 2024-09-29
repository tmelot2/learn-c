#include <stdio.h>

void avgSum(double a[], int n, double *avg, double *sum) {
	for (int i = 0; i < n; i++) {
		*sum += a[i];
	}

	*avg = *sum / n;
}

int main(void) {
	int N = 10;
	double a[N];

	// Init array
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
		printf("%.1f  ", a[i]);
	}
	printf("\n");

	double avg = 0;
	double sum = 0;
	avgSum(a, N, &avg, &sum);
	printf("avg = %.2f, sum = %.1f\n", avg, sum);

	return 0;
}