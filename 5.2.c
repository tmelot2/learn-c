#include <stdio.h>


void print_12h_time(int h, int m) {
	printf("%02d:%02d   ", h, m);
	if (h == 0 || h == 24) {
		printf("%02d:%02d AM\n", 12, m);
	} else if (h < 12) {
		printf("%02d:%02d AM\n", h, m);
	} else if (h == 12) {
		printf("%02d:%02d PM\n", h, m);
	} else if (h > 12) {
		printf("%02d:%02d PM\n", h-12, m);
	}
}

int main(void) {
	printf("24h     12h\n");

	for (int i = 0; i <= 24; i++) {
		for (int j = 0; j < 60; j++) {
			print_12h_time(i, j);
		}
	}

	return 0;
}