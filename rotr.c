#include "monty.h"

/**
 * rotr - Rotates the stack/queue
 * @stack: Pointer to pointer to the top stack element
 * @line_number: Line number in the monty bytecode file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur, *prev, *temp;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		;
	else
	{
		cur = *stack;
		prev = NULL;
		*stack = NULL;

		while (cur)
		{
			*stack = cur->next;
			temp = cur->next;
			cur->next = cur->prev;
			cur->prev = temp;
			prev = cur;
			cur = *stack;
		}
		*stack = prev;
	}
}
