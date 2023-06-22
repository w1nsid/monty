#include "monty.h"

bus_t bus = { NULL, NULL, NULL, 0 };

#define ERR_USAGE 1
#define ERR_FILE 2

/**
 * check_usage - check if the program is called with the correct number
 * of arguments
 * @argc: number of arguments
 * Return: void
 */
void check_usage(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(ERR_USAGE);
	}
}

/**
 * open_file - open a file
 * @filename: file name
 * @file: pointer to file
 * Return: void
 */
void open_file(char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	bus.file = *file;

	if (!(*file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(ERR_FILE);
	}
}

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	check_usage(argc);

	open_file(argv[1], &file);

	for (counter = 1; getline(&content, &size, file) != -1; counter++)
	{
		bus.content = content;
		execute_line(content, &stack, counter, file);
		free(content);
		content = NULL;
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
