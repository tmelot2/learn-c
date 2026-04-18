#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  bool digit_seen[10] = {false};
  int digit;
  long n;

  bool has_dupes = false;
  int dupes[10] = {false};

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]) {
      dupes[digit] = true;
	  has_dupes = true;
    }
    digit_seen[digit] = true;
    n /= 10;
  }

  if (has_dupes) {
    printf("Repeated digits: ");
	for (int i = 0; i < 10; i++) {
		if (dupes[i] == true) {
			printf("%d ", i);
		}
	}
	printf("\n");
  } else {
    printf("No repeated digits\n");
  }

  return 0;
}
