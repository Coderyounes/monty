#include "monty.h"

/**
 * op_div - divide second top element to top element
 * @stack: pointer to pointer to our stack
 * @counter: number of line
 */

void op_div(stack_t **stack, unsigned int counter)
{
	int res = 0, length;
	stack_t *node;

	length = getlen(*stack);
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (length >= 2)
	{
		res = (*stack)->next->n / (*stack)->n;
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
		node->n = res;
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
