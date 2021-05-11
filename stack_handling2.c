#include "monty.h"

/**
 * clear_stack - clears the whole stack
 * @head: top of stack_t stack
 * Return: nothing
 */
void clear_stack(stack_t *head)
{
	stack_t *tmp;

	if (head)
	{
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}

/**
 * stack_length - the number of nodes in the stack
 * @head: the top of the stack
 * Return: number of nodes in stack
 */
int stack_length(stack_t *head)
{
	int i = 0;

	if (!head)
		return (0);

	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
