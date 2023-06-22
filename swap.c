#include "monty.h"

/**
 * swap_f - Swaps the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Current line number in the file.
 */
void swap_f(stack_t **head, unsigned int counter)
{
	int temp = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		free_all_resources(bus.file, bus.content, *head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
