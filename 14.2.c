#include <stdio.h>

// Pretty sure this only works with array names, and if you pass to a function it breaks
// since array names pass as pointers, right? Yes!
#define NELEMS(a) (sizeof((a)) / sizeof((a[0])))

void f(int *x) {
	printf("func NELEMS(x) = %zu\n", NELEMS(x));
}

int main(void) {
	int x[] = {1,2,3,4,5,6};
	printf("NELEMS(x) = %zu\n", NELEMS(x));
	f(x);
	return 0;
}