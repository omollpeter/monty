#include "monty.h"

/**
 * pint - Prints the value at the top of the stack/queue
 * @stack: Pointer to pointer to the top of the stack
 * @line_number: Line number in the monty bytecode file
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
