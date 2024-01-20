#include "monty.h"
/**
 * divide - divides the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to the pointer to the top element of the stack
 * @line_number: current number line to the monty bytecodes
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
	free(temp);
}
