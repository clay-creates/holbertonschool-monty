#include "monty.h"

/**
 * swap - swaps top two elements of a stack
 * @stack: pointer to beginning of stack
 * @line_number: current line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = (*stack)->next;

	top->next = second_top->next;
	if (top->next != NULL)
	{
		top->next->prev = top;
	}

	second_top->next = top;
	second_top->prev = top->prev;
	if (second_top->prev != NULL)
	{
		second_top->prev->next = second_top;
	}

	top->prev = second_top;
	*stack = second_top;
}
