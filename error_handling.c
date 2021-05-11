#include "monty.h"

/**
 * print_stderr - prints error message or string to stderr
 * @s: character pointer to string to be printed
 * Return: nothing
 */
void print_stderr(char *s)
{
	fputs(s, stderr);
	exit(EXIT_FAILURE);
}

/**
 * clean_exit - frees, closes file and exits with error
 * Return: nothing
 */
void clean_exit(void)
{
	free(s_utils.instruction);
	close_file();
	exit(EXIT_FAILURE);
}
