#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: pointer to pointer to the top elem of stack
 * @line_number: line number in monty bytecode file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n + (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
	free(temp);
}
