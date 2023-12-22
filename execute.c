#include "monty.h"

/**
 * execute_instruction - execute an instruction from the Monty file
 * @line: instruction to execute
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number
 */

void execute_instruction(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	opcode = strtok(line, " \n");
	if (!opcode || opcode[0] == '#')
		return;

	for (int i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
