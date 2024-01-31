#include "monty.h"

/**
 * create_node - Create a stack_t node
 * @value: n member of node
 *
 * Return: pointer to created node
*/

stack_t *create_node(int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		handle_error(4);
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/**
 * free_stack - Frees the stack
 *
 * Return: void
 */

void free_stack(void)
{
	stack_t *ptr;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if number, 0 if not
*/

int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * is_line_empty - checks if a line is empty
 * @line: line to check
 *
 * Return: 1 if empty, 0 if not
*/

int is_line_empty(const char *line)
{
	while (*line != '\0')
	{
		if (!isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

/**
 * handle_error - Prints relevant error message and exits
 * @reference: error reference number
 *
 * Return: void
*/

void handle_error(int reference, ...)
{
	va_list ag;
	char *opcode;
	int line_number;

	va_start(ag, reference);
	switch (reference)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_number = va_arg(ag, int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
