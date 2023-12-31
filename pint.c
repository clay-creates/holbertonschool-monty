#include "monty.h"

/**
 * pint - prints the value at top of stack
 * @stack: pointer to beginning of stack
 * @line_number: current line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
