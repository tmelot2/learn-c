#include <stdio.h>

#define CUBE_OF(x) (x*x*x)
#define DIV_4(x) (x%4)
#define COMP_PROD(x,y) (x*y < 100 ? x*y : 0)

#define NELEMS(x) ((int) (sizeof(x) / sizeof(x[0])))

#define DOUBLE(x) (2*x)

#define AVG(x,y)  (((x)+(y))/2)
#define AREA(x,y) ((x)*(y))

#define PRINT_INT(n) printf(#n " = %d\n", n)
#define DISP(f,x)    printf(#f "(%d) = %d\n", x, f(x))
#define DISP2(f,x,y) printf(#f "(%d,%d) = %d\n", x, y, f(x,y))


int timesTwo(int x) {
	return x*2;
}

int times(int x, int y) {
	return x*y;
}


int main(void) {
	int x = CUBE_OF(2);
	printf("cube x 2 = %d\n", x);

	x = DIV_4(13);
	printf("div4 x 13 = %d\n", x);

	x = COMP_PROD(5,10);
	printf("comp prod 5 10 = %d\n", x);
	x = COMP_PROD(11,10);
	printf("comp prod 11 10 = %d\n", x);

	int y[] = {5,4,3,2,1};
	printf("nelems %d\n", NELEMS(y));

	printf("DOUBLE(2) = %d\n", DOUBLE(2));
	/*
		4 / DOUBLE(2)
		= 4 / 2 * x
		= 4 / 2 * 2
		= 2 * 2
		= 4
	*/
	printf("4/DOUBLE(2) = %d\n", 4/DOUBLE(2));

	printf("1/AREA(4,3) = %f\n", 1.0/AREA(4.0,3.0));

	char str[] = "abc";
	printf("%c\n", str[3]);

	printf("print int \n");
	x = 10;
	PRINT_INT(x);

	printf("disp(f,x)\n");
	DISP(timesTwo, x);

	printf("disp2(f,x,y)\n");
	x = 10;
	int z = 20;
	DISP2(times, x, z);

	return 0;


}