#include "monty.h"

/**
 * pall - Prints all the stack elements
 * @stack: Pointer to pointer to the first node in the stack/queue
 * @line_number: Line number in the bytecode file that contains the opcode
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
