#include <math.h>
#include <stdio.h>

#define DISP(f,x) printf(#f "(%f) = %f\n", x, (f)((x)))
#define DISP2(f,x,y) printf(#f "(%d,%d) = %d\n", x, y, (f)((x),(y)))

int max(float a, float b) {
	if (a > b) {
		return a;
	} else if (b > a) {
		return b;
	} else {
		return a;
	}
}

int main(void) {
	printf("%f\n", sqrt(64));
	DISP(sqrt, 64.0);
	DISP2(max, 32, 64);

	return 0;
}