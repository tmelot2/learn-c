#include <stdio.h>

#define AVG(x,y) (x+y)/2
#define AVG2(x,y) (((x)+(y))/2)

#define AREA(x,y) (x)*(y)
#define AREA2(x,y) ((x)*(y))

int main(void) {
	printf("A AVG(2,4) = %d\n", AVG(2,4));
	printf("B  %f\n", 1/AVG(2,4));
	printf("B2 %f\n", 1/AVG2(2,4));

	printf("A AREA(2,4) = %d\n", AREA(2,4));

	return 0;
}