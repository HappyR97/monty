#include "monty.h"

/**
 * nop - doesn't do anythin
 * @stack: pointer to stack node
 * @line_number: line for opcode
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack node
 * @line_number: line for opcode
 *
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (head == NULL)
		handle_more_error(10, line_number);
	if (head->n < 0 || head->n > 127)
		handle_more_error(11, line_number);
	printf("%c\n", head->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to stack node
 * @line_number: line for opcode
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;
	(void) stack;

	if (head == NULL)
	{
		printf("\n");
		return;
	}
	temp = head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
