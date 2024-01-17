#include "monty.h"
/**
 * pop - removes the element at the top of the stack/queue
 * @stack: pointer to pointer to the top element of the stack
 * @line_number: line number in the monty bytecode file
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;

	if (del->next)
	{
		*stack = del->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(del);
}
