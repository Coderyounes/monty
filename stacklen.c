#include "monty.h"

/**
 * getlen - function to get the len of stack
 * @stack: is our stack to check
 * Return: the exact length of stack
 */

int getlen(stack_t *stack)
{
	stack_t *temp;
	int len = 0;

	temp = stack;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	return (len);
}

