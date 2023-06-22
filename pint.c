#include "monty.h"

/**
 * f_pint - Prints the top of the stack
 * @stack: Pointer to the stack
 * @line_number: The current line number
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all_resources(bus.file, bus.content, *stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
