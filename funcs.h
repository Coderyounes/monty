#ifndef FUNCS_H
#define FUNCS_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct taxi_t - struct hold some data so I can call it in other files
 * @filehold: hold file pointer
 * @arg: hold number(as string)
 *
 * Description: struct to faciliate the data calling
 */
typedef struct taxi_t
{
	FILE *filehold;
	char *arg;
} taxi_t;

extern taxi_t Taxi;

char *tokenize(char *content, char **op);
int execute_instruction(char *op, stack_t **stack, unsigned int counter);
void f_push(stack_t **stack, unsigned int counter);
void f_pall(stack_t **stack, unsigned int counter);

#define BUFF 1024

#endif /* FUNCS_H  */
