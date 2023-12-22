#include "monty.h"

/**
 * push - adds to the stack
 * @line_num: line number
 * @value: value
 * @stack: stack
 */

void push(stack_t **stack, int line_num, int *value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value == NULL || !isdigit(*value + '0'))
	{
<<<<<<< HEAD
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
=======
		printf("Error: malloc failed\n");
>>>>>>> 9691a207c2d3779dd77bc35a48e16ad648c7af31
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = *value;
	new_node->prev = NULL;
	new_node->next = *stack;
<<<<<<< HEAD

	if (*stack != NULL)
		(*stack)->prev = new_node;

=======
>>>>>>> 9691a207c2d3779dd77bc35a48e16ad648c7af31
	*stack = new_node;
}
