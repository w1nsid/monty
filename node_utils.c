#include "monty.h"

/**
 * addnode - Adds a node to the top of the stack.
 * @head: Double pointer to the head of the stack.
 * @n: The value for the new node.
 */
void addnode(stack_t **head, int n)
{
	stack_t *newNode;
	stack_t *temp = *head;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = newNode;

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	*head = newNode;
}
