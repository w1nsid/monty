#include "monty.h"

/**
 * pchar_f - Prints the char at the top of the stack, followed by a new line.
 * @head: Pointer to the stack head.
 * @counter: Current line number in the file.
 */
void pchar_f(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		free_all_resources(bus.file, bus.content, *head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		free_all_resources(bus.file, bus.content, *head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}
