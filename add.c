#include "monty.h"
/**
 * add - adds top two elements of the stack
 * @stack: points to the pointer 
 * @line_number: line number in monty
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n + (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
}
