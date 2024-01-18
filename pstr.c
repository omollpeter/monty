#include "monty.h"

/**
 * pstr - Prints all the characters in stack until end or zero is met
 * @stack: Pointer to pointer to the first node in the stack/queue
 * @line_number: Line number in the bytecode file that contains the opcode
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = *stack;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	fprintf(stdout, "\n");
}
