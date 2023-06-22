#include "monty.h"

/**
 * f_pop - Removes the top item of the stack
 * @stack: Pointer to the stack
 * @line_number: The current line number
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all_resources(bus.file, bus.content, *stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
