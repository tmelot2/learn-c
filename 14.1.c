#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER_4(x) ((x) % 4)
#define THING(x,y) (((x) * (y)) < 100 ? 1 : 0)

int main(void) {
	int x = 2;
	printf("CUBE(%d) = %d\n", x, CUBE(x));
	int y = 13;
	printf("REMAINDER_4(%d) = %d\n", y, REMAINDER_4(y));
	int z1 = 5;
	int z2 = 20;
	printf("THING(%d, %d) = %d\n", z1, z2, THING(z1, z2));

	return 0;
}