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

	current_node->prev->next = NULL;
	tmp->prev = current_node;
	current_node->next = tmp;
	current_node->prev = NULL;
	*stack = current_node;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void stack(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	s_utils.dt_type = "stack";
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void queue(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	s_utils.dt_type = "queue";
}
