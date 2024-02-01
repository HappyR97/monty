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

/**
 * divide - divides the top two elements of the stack
 * @stack: pointer to stack node
 * @line_number: number of the line for opcode
 *
 * Return: void
 */

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL || head->next == NULL)
		handle_more_error(8, line_number, "div");
	if (head->n == 0)
		handle_more_error(9, line_number);
	head->next->n /= head->n;
	temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to stack node
 * @line_number: number of the line for opcode
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL || head->next == NULL)
		handle_more_error(8, line_number, "mul");

	head->next->n *= head->n;
	temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

/**
 * mod - computes the rest from two top elements of stack
 * @stack: pointer to stack node
 * @line_number: number of the line for opcode
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (head == NULL || head->next == NULL)
		handle_more_error(8, line_number, "mod");
	if (head->n == 0)
		handle_more_error(9, line_number);
	head->next->n %= head->n;
	temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

