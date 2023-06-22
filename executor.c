#include "monty.h"

/**
 * execute_line - Execute a line of the Monty file
 * @content: Line content
 * @stack: Head of the stack
 * @counter: Line counter
 * @file: Pointer to the Monty file
 *
 * Return: Always 0 if opcode is successful, 1 otherwise
 */

int execute_line(
	char *content,
	stack_t **stack,
	unsigned int counter,
	FILE *file)
{
	instruction_t opst[] = { { "push", push_f }, { "pall", pall_f },
							 { "pint", pint_f }, { "pop", pop_f },
							 { "swap", swap_f }, { "add", add_f },
							 { "nop", nop_f },	 { "queue", queue_f },
							 { NULL, NULL } };
	char *op;
	unsigned int i;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode && op; i++)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		cleanup(content, file, stack);
	}

	return (1);
}

/**
 * cleanup - Cleanup resources on error
 * @content: Line content
 * @file: Pointer to the Monty file
 * @stack: Head of the stack
 *
 * Description: This function closes the file, frees the content and the stack,
 * and then exits with EXIT_FAILURE.
 */

void cleanup(char *content, FILE *file, stack_t **stack)
{
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
