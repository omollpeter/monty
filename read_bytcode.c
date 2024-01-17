#include "monty.h"

char **args = NULL;

/**
 * read_bytecode - Reads every line in a monty bytecode file
 * @file: Pointer to monty bytecode file
 * @stack: Pointer to pointer to the first element in the stack/queue
 *
 * Return: nothing
 */
void read_bytecode(FILE *file, stack_t **stack)
{
	char buffer[512];
	int len, exists, i;
	unsigned int line_number = 1;
	instruction_t instr[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}};
		/* {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub}, {"div", divide},
		{"mul", mul}, {"#", hash}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", stack_st}, {"queue", queue},
		{NULL, NULL}};
		*/

	while (fgets(buffer, 511, file) != NULL)
	{
		exists = 0;
		len = (int) strlen(buffer);
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		args = parser(buffer, " ");
		for (i = 0; instr[i].opcode; i++)
		{
			if (strcmp(args[0], instr[i].opcode) == 0)
			{
				exists = 1;
				break;
			}
		}
		if (!exists)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, args[0]);
			exit(EXIT_FAILURE);
		}
		instr[i].f(stack, line_number);
		line_number += 1;
	}
}
