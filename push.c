#include "monty.h"

/***/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->line_number = line_number;
	new_node->next = *stack;
	*stack - new_node;
}