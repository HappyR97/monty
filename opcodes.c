#include "monty.h"

/**
 * push - Handles push opcode
 * @stack: node to push into stack
 * @line_number: Line number (unused)
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *stack;
		return;
	}

	temp = head;
	head = *stack;
	head->next = temp;
	temp->prev = head;
}

/**
 * pall - Handles pall opcode
 * @stack: node (unused)
 * @line_number: Line number (unused)
 *
 * Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;
	(void) stack;

	if (head == NULL)
		return;
	tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack node (unused)
 * @line_number: number of line for opcode
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (head == NULL)
		handle_error(6, line_number);
	printf("%d\n", head->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack node (unused)
 * @line_number: number of line for opcode
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL)
		handle_error(7, line_number);
	temp = head;
	head = head->next;
	if (head != NULL)
		head->prev = NULL;
	free(temp);
}
