#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack node
 * @line_number: number of the line for opcode
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL || head->next == NULL)
		handle_more_error(8, line_number, "add");

	head->next->n += head->n;
	temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: pointer to stack node
 * @line_number: number of the line for opcode
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL || head->next == NULL)
		handle_more_error(8, line_number, "sub");

	head->next->n -= head->n;
	temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

