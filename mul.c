#include "monty.h"

/**
 * mul - Multiplies top two elements of the stack
 * @stack: pointer to pointer to the top elem of stack/queue
 * @line_number: line number in monty
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
}
