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
	unsigned int line_number = 1;
	char *token, *ptr1, *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = open_read_file(argv[1]);
	token = strtok_r(buffer, "\n", &ptr1);
	while (token)
	{
		execute(token, line_number);
		token = strtok_r(NULL, "\n", &ptr1);
		line_number++;
	}
	line_number--;
	free(buffer);
	return (0);
}

/**
 * execute - executes the opcode
 * @command: command string
 * @line_number: number of the line
 *
 * Return: void
*/

void execute(char *command, int line_number)
{
	char *cmd[2], *temp, *ptr2;
	int i = 0;
	stack_t *node;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{'\0', 0},
	};
	temp = strdup(command);
	cmd[0] = strtok_r(temp, " ", &ptr2);
	cmd[1] = strtok_r(NULL, " ", &ptr2);
	if (strcmp(cmd[0], "push") == 0)
	{
		if (cmd[1] == NULL || !is_number(cmd[1]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		node = create_node(atoi(cmd[1]));
	}

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, cmd[0]) == 0)
			opcodes[i].f(&node, line_number);
		i++;
	}
	free(temp);
}
