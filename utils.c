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
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
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

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
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
