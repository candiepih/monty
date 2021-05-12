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
 * try removing me and your code breaks.
 * Return: absolutely nothing
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack.
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int difference = 0;
	stack_t *head;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean_exit();
	}

	head = *stack;
	difference = (head->next->n - head->n);
	remove_node_start(stack, *stack);
	(*stack)->n = difference;
}

/**
 * div2 - divides the second top element of the stack by the top element
 * of the stack.
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 * Return: nothing
 */
void div2(stack_t **stack, unsigned int line_number)
{
	int division = 0;
	stack_t *head;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		clean_exit();
	}

	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean_exit();
	}
	division = (head->next->n / head->n);
	remove_node_start(stack, *stack);
	(*stack)->n = division;
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product = 0;
	stack_t *head;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		clean_exit();
	}

	head = *stack;
	product = (head->next->n * head->n);
	remove_node_start(stack, *stack);
	(*stack)->n = product;
}
