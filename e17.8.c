#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

void *mymalloc(size_t size) {
	void *ptr = malloc(size);
	if (ptr == NULL) {
		printf("No memory\n");
	}
	return ptr;
}

struct node *stack_push(struct node *top, int v) {
	struct node *new = mymalloc(sizeof(struct node));
	new->value = v;

	if (top == NULL) {
		new->next = top;
		return new;
	} else {
		new->next = top;
		return new;
	}
}

struct node *stack_pop(struct node *top, int *popped_value) {
	if (top == NULL) {
		printf("Empty stack, nothing to pop\n");
		return top;
	}

	*popped_value = top->value;
	struct node *new_top = top->next;
	free(top);
	return new_top;
}

void stack_print(struct node *top) {
	struct node *cur = top;
	int n = 0;
	while (cur != NULL) {
		printf("%d ", cur->value);
		cur = cur->next;
		n += 1;
	}
	if (n > 0) printf("\n");
}

int main(void) {
	int n = 3;
	int p;
	struct node *stack = NULL;

	for (int i = 0; i < n; i++) {
		stack = stack_push(stack, i);
		stack_print(stack);
	}
	for (int i = 0; i < n+1; i++) {
		stack = stack_pop(stack, &p);
		stack_print(stack);
	}

	return 0;
}