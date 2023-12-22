#include "monty.h"

/**
 * pall - opcode to print all elements of the stack
 * @stack: pointer to the beginning of the stack
 * @line_number: line number being executed
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
