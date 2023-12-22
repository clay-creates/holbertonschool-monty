#include "monty.h"

instruction_t instruction[] =
	{
		{"push", (void (*)(stack_t **, unsigned int))push},
		{"pall", (void (*)(stack_t **, unsigned int))pall},
		{"pint", (void (*)(stack_t **, unsigned int))pint},
		{"pop", (void (*)(stack_t **, unsigned int))pop},
		{"swap", (void (*)(stack_t **, unsigned int))swap},
		{"add", (void (*)(stack_t **, unsigned int))add},
		{"nop", (void (*)(stack_t **, unsigned int))nop},
};

/**
 * find_opcode - finds the opcode to use
 * @opcode: opcode to search for
 * @stack: stack to search in
 * @line_number: line number
 */

void find_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	size_t i;

	for (i = 0; i < sizeof(instruction) / sizeof(instruction[0]); i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_number);
			return;
		}
	}
	printf("Unknown opcode: %s\n", opcode);
}
