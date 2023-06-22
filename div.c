#include "monty.h"

/**
 * div_f - Divides the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Current line number in the file.
 */
void div_f(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		free_all_resources(bus.file, bus.content, *head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free_all_resources(bus.file, bus.content, *head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
