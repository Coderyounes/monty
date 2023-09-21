#include "monty.h"


/**
 * op_pop - remove the top element of stack
 * @stack: pointer to pointer to our stack
 * @counter: line number
 */

void op_pop(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
