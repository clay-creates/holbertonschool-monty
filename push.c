#include "monty.h"

/**
 * push - opcode to push an element onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value_str;

	UNUSED(line_number);

	value_str = strtok(NULL, " \n");
	if (!value_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value_str);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
