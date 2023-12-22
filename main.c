#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: array or arguments
 *
 * Return: return 1 or 0 based on success or fail
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;

		// TODO: Add parsing and opcode execution code here
		char *token = strtok(line, "\t\n ");
		if (token == NULL)
		{
			continue;
		}

		instruction_t instructions[] =
			{
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{NULL, NULL}};

		void (*opcode_func)(stack_t **, unsigned int) = find_opcode(token, instructions);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			return (EXIT_FAILURE);
		}
		opcode_func(&stack, line_number);
	}

	free(line);
	fclose(fp);

	return (EXIT_SUCCESS);
}
