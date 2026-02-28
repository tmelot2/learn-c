#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
	struct node *cur = list, *prev = NULL;

	// Start new list.
	if (list == NULL) {
		new_node -> next = NULL;
		list = new_node;
		return list;
	}

	// Find node to insert.
	while (cur != NULL && cur -> value <= new_node -> value) {
		prev = cur;
		cur = cur -> next;
	}

	// If inserting at head of list.
	if (prev == NULL) {
		prev = new_node;
		new_node -> next = cur;
		list = prev;
		return list;
	}

	// Normal insert in middle or end.
	prev -> next = new_node;
	new_node -> next = cur;

	return list;
}

int main(void) {
	struct node *first = NULL;

	for (int i = 0; i < 10; i++) {
		struct node *new_node = malloc(sizeof(struct node));
		new_node -> value = 100-i;
		first = insert_into_ordered_list(first, new_node);
	}

	struct node *new_node = malloc(sizeof(struct node));
	new_node -> value = 105;
	first = insert_into_ordered_list(first, new_node);

	for (struct node *cur = first; cur != NULL; cur = cur -> next) {
		printf("%d\n", cur -> value);
	}

	return 0;
}