#include "funcs.h"


/**
 * f_pall - function to print all element in stack
 * @stack: pointer to pointer to our stack
 * @counter: line number
 * Return: nothing it's a void
 */
void f_pall(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
