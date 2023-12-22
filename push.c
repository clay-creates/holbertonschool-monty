#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack to work with
 * @line_num: line number
 * @value: value
 */

void push(stack_t **stack, int line_num, int *value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value == NULL || !isdigit(*value + '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = *value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
