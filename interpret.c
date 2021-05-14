#include "monty.h"

/**
 * process_instructions - handles instruction line per line from a file
 * @line_number: current instruction line_number in file
 * @stack: a stack_t stack
 * Return: nothing
 */
void process_instructions(unsigned int *line_number, stack_t **stack)
{
	char *duplicate_line, *token;
	char *delimeter = " '\r''\n''\t'";
	void (*instruction_f)(stack_t **stack, unsigned int line_number);

	duplicate_line = strdup(s_utils.instruction);
	token = strtok(duplicate_line, delimeter);

	if (token)
	{
		*line_number += 1;
		if (token[0] == '#')
			instruction_f = get_instruction("#");
		else
			instruction_f = get_instruction(token);

		if (instruction_f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token);
			free(duplicate_line);
			clear_stack(*stack);
			clean_exit();
		}
		free(duplicate_line);
		instruction_f(stack, *line_number);
	}
	else
	{
		if (*line_number > 0)
			*line_number += 1;
		free(duplicate_line);
	}
}

/**
 * get_instruction - gets the operation needed for the current instruction
 * @cmd: string pointer to certain instruction
 * Return: pointer to function that handles the instruction or NULL if no
 * operation related to the provided @command
 */
void (*get_instruction(char *cmd))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t opts[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div2},
		{"mul", mul},
		{"mod", mod},
		{"#", comments},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	if (!cmd)
		return (NULL);

	while (opts[i].opcode != NULL)
	{
		if (strcmp(cmd, opts[i].opcode) == 0)
			return (opts[i].f);
		i++;
	}
	return (NULL);
}
