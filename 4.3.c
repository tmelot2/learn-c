#include <stdio.h>

int main(void) {
	printf("Enter three numbers: ");
	int n1,n2,n3;
	scanf("%1d%1d%1d", &n1, &n2, &n3);
	printf("Reversed: %d%d%d\n", n3, n2, n1);

	return 0;
}