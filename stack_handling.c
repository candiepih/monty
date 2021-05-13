#include "monty.h"

/**
 * print_stack - prints the values in the stack
 * @head: the top of stack_t stack
 * Return: number of nodes available in a stack
 */
int print_stack(stack_t *head)
{
	int i = 0;

	if (!head)
		return (0);

	while (head)
	{
		i++;
		printf("%d\n", head->n);
		head = head->next;
	}
	return (i);
}

/**
 * add_node_head - adds a new node to the top of stack
 * @head: the top of stack_t stack
 * @n: integer value of the stack_t stack
 * Return: new element created on succes of NULL on failure
 */
stack_t *add_node_head(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (NULL);
	if (*head)
		(*head)->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;

	return (new_node);
}

/**
 * add_node_end - adds a new node to the bottom of the stack
 * @head: top of stack_t stack
 * @n: integer data value to @n of stack_t stack
 * Return: new element created on success or NULL if adding node failed
 */

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *h = *head;

	if (!head)
		return (NULL);
	if (!*head)
		return (add_node_head(head, n));

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		print_stderr("Error: malloc failed\n");
		return (NULL);
	}
	while (h->next)
		h = h->next;

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = h;
	h->next = new_node;
	return (new_node);
}

/**
 * remove_node_start - removes top most element of stack_t stack
 * @head: top of stack_t stack
 * @current_node: the element count from index 0
 * Return: (1) on Success (-1) of failure
 */

int remove_node_start(stack_t **head, stack_t *current_node)
{
	stack_t *tmp;

	if (!current_node->next)
	{
		free(current_node);
		*head = NULL;
		return (1);
	}
	else
	{
		tmp = current_node->next;
		free(current_node);
		tmp->prev = NULL;
		*head = tmp;
		return (1);
	}
	return (-1);
}
