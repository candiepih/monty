#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line_number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value, *dup_line;
	char *delimeter = " '\r''\n''\t'";
	stack_t *new_node = NULL;

	dup_line = strdup(s_utils.instruction);
	strtok(dup_line, delimeter);
	value = strtok(NULL, delimeter);

	if (!is_numeric(value) || value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(dup_line);
		clear_stack(*stack);
		clean_exit();
	}

	if (strcmp(s_utils.dt_type, "queue") == 0)
		new_node = add_node_end(stack, atoi(value));
	else
		new_node = add_node_head(stack, atoi(value));

	if (new_node == NULL)
	{
		print_stderr("Error: malloc failed\n");
		free(dup_line);
		clear_stack(*stack);
		clean_exit();
	}
	free(dup_line);
}

/**
 * pall - prints all elements in the stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line_number
 * Return: nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	print_stack(*stack);
}

/**
 * pint - prints top most element of stack
 * @stack: the top of stack_t stack
 * @line_number: current instruction line_number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top most element of stack_t stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line_number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}
	remove_node_start(stack, *stack);
}

/**
 * swap - swaps top two elements of stack_t stack
 * @stack: top element of stack_t stack
 * @line_number: current instruction line_number number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node;
	stack_t *other_node;
	stack_t *tmp;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}
	tmp = *stack;
	next_node = tmp->next;
	other_node = next_node->next;
	if (other_node)
		other_node->prev = next_node;
	tmp->next = other_node;
	tmp->prev = next_node;
	next_node->next = tmp;
	next_node->prev = NULL;
	*stack = next_node;
}
