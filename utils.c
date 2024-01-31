#include "monty.h"

/**
 * open_read_file - Opens and reads a file
 * @filename: Name of file to open and read
 *
 * Return: buffer (str)
*/

char *open_read_file(char *filename)
{
	int fd;
	ssize_t r;
	struct stat statbuf;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &statbuf) == -1)
	{
		fprintf(stderr, "Error: Can't get file size\n");
		close(fd);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(statbuf.st_size + 1);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(fd);
		exit(EXIT_FAILURE);
	}

	r = read(fd, buffer, statbuf.st_size);
	if (r == -1)
	{
		fprintf(stderr, "Error: Reading file\n");
		close(fd);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	buffer[r] = '\0';

	close(fd);
	return (buffer);
}

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
		return (NULL);
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
