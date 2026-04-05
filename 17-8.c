#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

bool stack_push(struct node **top, int value) {
	printf("Pushing %d\n", value);
	struct node *new_node = malloc(sizeof(struct node));

	// If OOM, return false.
	if (new_node == NULL) {
		return false;
	}

	new_node -> value = value;

	// Pushing into empty stack.
	if (*top == NULL) {
		new_node -> next = NULL;
		*top = new_node;
		return true;
	}

	// Pushing into not empty stack.
	new_node -> next = *top;
	*top = new_node;
	return true;
}

bool stack_pop(struct node **top, int *out_value) {
	if (*top == NULL) {
		return false;
	}

	struct node *node = *top;
	*top = node -> next;
	*out_value = node -> value;
	free(node);
	printf("Popping %d\n", *out_value);
	return true;
}

void stack_print(struct node *top) {
	printf("top -> [ ");
	for (struct node *cur = top; cur != NULL; cur = cur -> next) {
		printf("%d ", cur -> value);
	}
	printf("]\n");
}

int main() {
	struct node *stack = NULL;
	stack_push(&stack, 1); stack_print(stack);
	stack_push(&stack, 2); stack_print(stack);
	stack_push(&stack, 3); stack_print(stack);

	int num = 0;
	stack_pop(&stack, &num); stack_print(stack);
	stack_pop(&stack, &num); stack_print(stack);
	stack_pop(&stack, &num); stack_print(stack);

	return 0;
}