#include "monty.h"

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
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
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
		case 6:
			line_number = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			break;
		case 7:
			line_number = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * handle_more_error - Prints relevant error message and exits
 * @reference: error reference number
 *
 * Return: void
*/

void handle_more_error(int reference, ...)
{
	va_list ag;
	int line_number;
	char *opcode;

	va_start(ag, reference);
	switch (reference)
	{
		case 8:
			line_number = va_arg(ag, int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			break;
		case 9:
			line_number = va_arg(ag, int);
			fprintf(stderr, "L%d: division by zero\n", line_number);
			break;
		case 10:
			line_number = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		case 11:
			line_number = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
