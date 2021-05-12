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
