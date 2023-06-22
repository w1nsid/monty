#include "monty.h"

/**
 * f_push - Pushes an integer to a stack or a queue.
 * @head: Pointer to the stack/queue.
 * @counter: Current line number in the file.
 */

void f_push(stack_t **head, unsigned int counter)
{
	int n;
	int flag = 0;

	for (int j = (bus.arg && bus.arg[0] == '-' ? 1 : 0);
		 bus.arg && bus.arg[j] != '\0';
		 j++)
	{
		if (!isdigit(bus.arg[j]))
		{
			flag = 1;
			break;
		}
	}
	if (flag || !bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
	{
		addnode(head, n);
	} else
	{
		addqueue(head, n);
	}
}
