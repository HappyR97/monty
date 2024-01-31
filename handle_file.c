#include "monty.h"

/**
 * open_file - Opens file
 * @filename: name of file
 *
 * Return: void
*/

void open_file(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (fd == NULL || filename == NULL)
		handle_error(2, filename);
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - Reads file
 * @fd: file descriptor
 *
 * Return: void
*/

void read_file(FILE *fd)
{
	int line_number;
	char *buffer = NULL;
	size_t n;

	for (line_number = 1; getline(&buffer, &n, fd) != -1; line_number++)
		parse(buffer, line_number);
	free(buffer);
}
