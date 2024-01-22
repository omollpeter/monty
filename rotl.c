#include "monty.h"

/**
 * rotl - Rotates stack, top elem becomes last, second elem become top
 * @stack: Pointer to pointer to the top stack element
 * @line_number: Line number in the monty bytecode file
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		;
	else
	{
		temp = *stack;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		new = *stack;
		while (new->next)
		{
			new = new->next;
		}

		temp->next = NULL;
		temp->prev = new;
		new->next = temp;
	}
}
