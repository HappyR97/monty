#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point for the Monty program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_read_file(argv[1]);
	free_stack();
	return (0);
}

/**
 * open_read_file - Opens and reads a file
 * @filename: Name of file to open and read
 *
 * Return: buffer (str)
*/

void open_read_file(char *filename)
{
	char *buffer = NULL, *opcode, *value;
	size_t len = 0;
	int line_number;
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (is_line_empty(buffer))
			continue;
		printf("buffer: %s\n", buffer);
		opcode = strtok(buffer, "\n ");
		value = strtok(NULL, "\n ");
		printf("opcode: %s, value: %s\n", opcode, value);
		execute(opcode, value, line_number);
	}
	free(buffer);
	fclose(fd);
}

/**
 * execute - executes the opcode
 * @opcode: opcode to execute
 * @value: value associated to opcode
 * @line_number: number of the line
 *
 * Return: void
*/

void execute(char *opcode, char *value, int line_number)
{
	int i = 0;
	stack_t *node = NULL;
	instruction_t funcs[] = {{"push", push}, {"pall", pall}, {NULL, NULL},};

	if (strcmp(opcode, "push") == 0)
	{
		if (value == NULL || !is_number(value))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack();
			exit(EXIT_FAILURE);
		}
		node = create_node(atoi(value));
		push(&node, line_number);
		return;
	}
	while (funcs[i].opcode)
	{
		if (strcmp(funcs[i].opcode, opcode) == 0)
		{
			funcs[i].f(&head, line_number);
			break;
		}
		i++;
	}
	if (funcs[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_stack();
		exit(EXIT_FAILURE);
	}
}
