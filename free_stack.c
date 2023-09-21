#include "monty.h"

/**
 * free_stack - function to free stack
 *
 * @h: pointer to our stack
 */

void free_stack(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}

}
