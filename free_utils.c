#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 */
void free_stack(stack_t *head)
{
	stack_t *tempNode;

	while (head)
	{
		tempNode = head->next;
		free(head);
		head = tempNode;
	}
}
/**
 * free_all_resources - Frees all resources in case of an error
 * @file: Pointer to the file to be closed
 * @content: Pointer to the content to be freed
 * @stack: Pointer to the stack to be freed
 */
void free_all_resources(FILE *file, char *content, stack_t *stack)
{
	fclose(file);
	free(content);
	free_stack(stack);
}
