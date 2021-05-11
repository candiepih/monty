#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: current instruction line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *head;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}

	head = *stack;
	sum = (head->n + head->next->n);
	remove_node_start(stack, *stack);
	(*stack)->n = sum;
}

/**
 * nop - I do absolutely nothing
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Description: Am not all that useless. Don't belief me?
 * try removing and your code breaks.
 * Return: absolutely nothing
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}
