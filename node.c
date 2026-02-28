#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

int main(void) {
	struct node *first = NULL;
	struct node *last = NULL;

	for (int i = 0; i < 100; i++) {
		struct node *new_node = malloc(sizeof(struct node));
		if (new_node == NULL) {
			printf("Out of memory\n");
			return 1;
		}

		new_node -> value = i;
		new_node -> next = NULL;

		if (first == NULL) {
			first = new_node;
			last = new_node;
		} else {
			last -> next = new_node;
			last = new_node;
		}
	}

	for (struct node *cur = first; cur != NULL; cur = cur -> next) {
		printf("%d\n", cur -> value);
	}

	return 0;
}