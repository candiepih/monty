#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current_node;
	stack_t *tmp;

	if (stack_length(*stack) < 2)
		return;

	tmp = *stack;
	current_node = *stack;
	while (current_node->next)
		current_node = current_node->next;

	current_node->prev->next = tmp;
	tmp->next->prev = current_node;
	tmp->prev = current_node->prev;
	current_node->next = tmp->next;
	current_node->prev = NULL;
	tmp->next = NULL;
	*stack = current_node;
}
