#include <stdio.h>
#include <math.h>


long int power(long int base, int exp) {
    long int res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}


int main(void)
{
  long int i, n;

  // printf("This program prints a table of squares.\n");
  // printf("Enter number of entries in table: ");
  // scanf("%ld", &n);

  // 3037100001 -9222767657635351615
  printf("sizeof %zld\n", sizeof(i));

  printf("%-20s%20s%20s\n", "i", "2^i", "2^i-1");
  for (i = 1; i <= 64; i+=1)
    printf("%-20ld %20ld %20ld\n", i, power(2,i), power(2,i)-1);

  /*
  	Smallest n that breaks as int: 46341
	46340           2147395600
	46341          -2147479015
	32 bit

  	Smallest n that breaks as short int: 182
	181                32761
	182               -32412
	16 bit

	Smallest n that breaks as short int:
	DUNNO but its 64 bit and thats the answer
  */

  return 0;
}
