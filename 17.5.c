#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

int cmp(const void *a, const void *b) {
	char *aa = *(const char **)a;
	char *bb = *(const char **)b;
	return strcmp(aa, bb);
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

int main(void) {
	char *words[20];
	int num_words = 0;
	char *s = NULL;
	int read_count = 0;

	do {
		printf("Enter a word: ");
		fflush(stdout);
		s = malloc(sizeof(char) * MAX_LEN);
		read_count = read_line(s, MAX_LEN);

		if (read_count == 0) {
			break;
		}

		words[num_words++] = s;

		printf("%s\n", s);
	} while (read_count > 0);

	qsort(words, num_words, sizeof(char *), cmp);
	for (int i = 0; i < num_words; i++) {
		printf("%s ", words[i]);
	}
	printf("\n");

	return 0;
}
