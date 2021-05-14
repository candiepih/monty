#include "monty.h"

/**
 * open_file - opens a file
 * @filename: string pointer to file name
 * Return: nothing
 */
void open_file(char *filename)
{
	s_utils.fp = fopen(filename, "r");
	if (s_utils.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_file - reads the content of a file
 * Return: nothing
 */
void read_file(void)
{
	size_t line_count = 0;
	unsigned int line_number = 0;
	stack_t *head;

	head = NULL;
	while ((getline(&s_utils.instruction, &line_count, s_utils.fp)) != -1)
		process_instructions(&line_number, &head);

	clear_stack(head);
	free(s_utils.instruction);
}

/**
 * close_file - closes an opened file
 * Return: nothing
 */
void close_file(void)
{
	if (s_utils.fp)
		fclose(s_utils.fp);
}

/**
 * handle_file - calls all file handling functions
 * @filename: string pointer to file name
 * Return: nothing
 */
void handle_file(char *filename)
{
	open_file(filename);
	read_file();
	close_file();
}
