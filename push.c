#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack to target
 * @line_number: line number
 * @n: value in new node
 */

void push(stack_t **stack, unsigned int line_number, int n)
{
	/* Create a new node and add it to the stack */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
