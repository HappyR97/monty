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
		handle_error(1);
	open_file(argv[1]);
	free_stack();
	return (0);
}
