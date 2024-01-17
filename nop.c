#include "monty.h"

/**
 * nop - Doesn't do anything
 * @stack: Pointer to pointer to the the top stack element
 * @line_number:L Line number in the monty bytecode file
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	;
}
