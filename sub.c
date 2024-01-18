#include "monty.h"

/**
 * sub - Subtracts top two elements of the stack(second - first)
 * @stack: points to the pointer
 * @line_number: line number in monty
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
}
