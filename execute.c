#include "monty.h"

/**
 * parse - parses opcode command
 * @buffer: line to parse
 * @line_number: number of line to parse
 *
 * Return: void
*/

void parse(char *buffer, int line_number)
{
	char *opcode, *value;

	if (buffer == NULL)
		handle_error(4);
	opcode = strtok(buffer, "\n ");
	if (opcode == NULL)
		return;
	value = strtok(NULL, "\n ");
	select_opcode(opcode, value, line_number);
}

/**
 * select_opcode - Selects appropriate function for opcode
 * @opcode: opcode to execute
 * @value: value of opcode
 * @line_number: number of the line for opcode
 *
 * Return: void
*/

void select_opcode(char *opcode, char *value, int line_number)
{
	int i, flag;

	instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; op_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
		{
			execute_opcode(op_list[i].f, opcode, value, line_number);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, line_number, opcode);
}

/**
 * execute_opcode - Calls function for relevant opcode
 * @func: pointer to function to call
 * @opcode: opcode to execute
 * @value: value of opcode
 * @line_number: numer of line of opcode
 *
 * Return: void
*/

void execute_opcode(opcode_func func, char *opcode,
		char *value, int line_number)
{
	stack_t *new_node;
	int sign = 1;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value++;
			sign = -1;
		}
		if (value == NULL)
			handle_error(5, line_number);
		for (i = 0; value[i] != '\0'; i++)
			if (isdigit(value[i]) == 0)
				handle_error(5, line_number);
		new_node = create_node(atoi(value) * sign);
		func(&new_node, line_number);
	}
	else
		func(&head, line_number);
}
