#include "monty.h"
/**
 * mod - computes the remainder from division of
 * the second top element of the stack by the top stack element
 * @stack: pointer to the pointer to the top element of the stack
 * @line_number: current number line to the monty bytecodes
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
}
