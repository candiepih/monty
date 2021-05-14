#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_t_utils - global variables
 * @instruction: string pointer to current instruction
 * @dt_type: string to the name of current data structure in use
 * @fp: pointer to the opened file
 *
 * Description: file pointer and current instruction being accessed
 */
typedef struct stack_t_utils
{
	char *instruction;
	char *dt_type;
	FILE *fp;
} utils;

/* global variable */
extern utils s_utils;
utils s_utils;

/* error handling prototypes*/
void print_stderr(char *s);
void clean_exit(void);

/* lists manipulating handling prototypes*/
int print_stack(stack_t *head);
stack_t *add_node_head(stack_t **head, int n);
stack_t *add_node_end(stack_t **head, int n);
int remove_node_start(stack_t **head, stack_t *current_node);
void clear_stack(stack_t *head);
int stack_length(stack_t *head);

/* file handling functions*/
void open_file(char *filename);
void read_file(void);
void close_file(void);
void handle_file(char *filename);

/* instructions interpratation prototypes */
void process_instructions(unsigned int *line_number, stack_t **stack);
void (*get_instruction(char *cmd))(stack_t **stack, unsigned int line_number);

/* instructions prototypes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div2(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void comments(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* string handling prototypes*/
int is_numeric(char *s);

#endif /* MONTY_H */
