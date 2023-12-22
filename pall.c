#include "monty.h"

/**
 * pall - print all elements in stack
 * @stack: stack to target
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
