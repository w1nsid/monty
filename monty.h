#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* utils */
void check_usage(int argc);
void open_file(char *filename, FILE **file);
int execute_line(
	char *content,
	stack_t **stack,
	unsigned int counter,
	FILE *file);
void cleanup(char *content, FILE *file, stack_t **stack);
void free_stack(stack_t *head);
void free_all_resources(FILE *file, char *content, stack_t *stack);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void queue_f(stack_t **head, unsigned int counter);
/* op codes */
void push_f(stack_t **head, unsigned int number);
void pall_f(stack_t **head, unsigned int number);
void pint_f(stack_t **head, unsigned int number);
void pop_f(stack_t **head, unsigned int number);
void swap_f(stack_t **head, unsigned int number);
void add_f(stack_t **head, unsigned int number);
void nop_f(stack_t **head, unsigned int number);
void sub_f(stack_t **head, unsigned int number);
void div_f(stack_t **head, unsigned int number);
void mul_f(stack_t **head, unsigned int number);
void mod_f(stack_t **head, unsigned int number);
void pchar_f(stack_t **head, unsigned int number);

#endif
