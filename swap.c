#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to pointer to the top element of the stack/queue
 * @line_number: Line number in the monty bytecode file
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = *stack;
	temp2 = (*stack)->next->next;
	*stack = (*stack)->next;

	(*stack)->next = temp1;
	(*stack)->prev = NULL;
	temp1->next = temp2;
	temp1->prev = *stack;
}
