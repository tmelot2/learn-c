#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int main() {
	struct node *first = NULL;
	struct node *last = NULL;

	for (int i = 0; i < 10; i++) {
		struct node *new_node = malloc(sizeof(struct node));
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