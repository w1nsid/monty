#include "monty.h"

/**
 * f_pall - Prints all elements in the stack, starting from the top.
 * @head: Double pointer to the head of the stack.
 * @counter: The current line number in the bytecode file. Not used in this
 * function.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *temp = NULL;

	(void)counter;
	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
