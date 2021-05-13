#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *head;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		clean_exit();
	}

	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean_exit();
	}
	mod = (head->next->n % head->n);
	remove_node_start(stack, *stack);
	(*stack)->n = mod;
}

/**
 * comments - I do absolutely nothing when i encounter instruction
 * that start with '#'
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void comments(__attribute__((unused)) stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}

/**
 * pchar - print the char at the top of the stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}

	printf("%c\n", value);
}

/**
 * pstr - print the string starting at the top of the stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}

	printf("\n");
}

/**
 * rotl -  rotates the stack to the top
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current_node;
	stack_t *tmp;

	if (stack_length(*stack) < 2)
		return;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	current_node = *stack;

	while (current_node->next)
		current_node = current_node->next;

	current_node->next = tmp;
	tmp->prev = current_node;
	tmp->next = NULL;
}
