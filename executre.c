#include "monty.h"

/**
 * execute_instruction - function to identify operation & call other functions
 *
 * @op: operation type or order
 * @stack: pointer to pointer to our stack
 * @counter: line number in the file
 * Return: 0 if Succed, 1 if fail
 */

int execute_instruction(char *op, stack_t **stack, unsigned int counter)
{
	instruction_t opst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(Taxi.filehold);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
