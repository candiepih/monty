#include "monty.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: array of string arguments
 * Return: (0) Success (1) on error
 */
int main(int argc, char **argv)
{
	s_utils.fp = NULL;
	s_utils.instruction = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	handle_file(argv[1]);

	return (0);
}
