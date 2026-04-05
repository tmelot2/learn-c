#include <stdio.h>

int main(void) {
	printf("Enter numbers from 1 to 16 in any order (16 of them):\n");
	int one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen;
	// 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &one,&two,&three,&four,&five,&six,&seven,&eight,&nine,&ten,&eleven,&twelve,&thirteen,&fourteen,&fifteen,&sixteen);

	printf("%d %d %d %d ", one, two, three, four);
	printf("%d %d %d %d ", five, six, seven, eight);
	printf("%d %d %d %d ", nine, ten, eleven, twelve);
	printf("%d %d %d %d\n", thirteen, fourteen, fifteen, sixteen);

	printf("Row sums: %d %d %d %d\n", one+two+three+four, five+six+seven+eight, nine+ten+eleven+twelve, thirteen+fourteen+fifteen+sixteen);
	printf("Col sums: %d %d %d %d\n", one+five+nine+thirteen, two+six+ten+fourteen, three+seven+eleven+fifteen, four+eight+twelve+sixteen);
	printf("Diag sums: %d %d\n", one+six+eleven+sixteen, four+seven+ten+thirteen);

	return 0;
}