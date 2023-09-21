#include "monty.h"

/**
 * op_add - sum top & second top element
 * @stack: pointer to pointer to our stack
 * @counter: number of line
 */

void op_add(stack_t **stack, unsigned int counter)
{
	int sum = 0;
	int length;
	stack_t *node;

	length = getlen(*stack);

	if (length >= 2)
	{
		sum = (*stack)->n + (*stack)->next->n;
		op_pop(stack, counter);
		op_pop(stack, counter);

		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "L%d: malloc failed\n", counter);
			fclose(Taxi.filehold);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		node->n = sum;
		node->next = *stack;
		node->prev = NULL;
		if (*stack)
		{
			(*stack)->prev = node;
		}

		*stack = node;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
