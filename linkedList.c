// Singly linked list, head node only

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node* createNode(int data) {
	Node *newNode = (Node*)(malloc(sizeof(Node)));
	if (!newNode) {
		printf("Failed to allocate node!");
		exit(EXIT_FAILURE);
	}
	newNode -> data = data;
	newNode -> next = NULL;

	return newNode;
}

void insertNode(Node **head, Node *newNode) {
	if (*head == NULL) {
		*head = newNode;
	} else {
		Node *cur = *head;
		while (cur -> next != NULL) {
			cur = cur -> next;
		}
		cur -> next = newNode;
	}
}

void freeList(Node *head) {
	Node *temp = NULL;
	Node *cur = head;

	while (cur != NULL) {
		temp = cur;
		cur = cur -> next;
		free(temp);
	}
}

void printList(Node *head) {
	while (head != NULL) {
		printf("%d", head -> data);
		if (head -> next != NULL) {
			printf(" -> ");
		}
		head = head -> next;
	}
}

int main(void) {
	Node *head = NULL;
	insertNode(&head, createNode(1));
	insertNode(&head, createNode(2));
	insertNode(&head, createNode(3));
	printList(head);

	freeList(head);
	head = NULL;

	return 0;
}
