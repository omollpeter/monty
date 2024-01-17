#include "monty.h"

/**
 * push - Adds a new node at the top of stack/ back of a queue
 * @stack: Pointer to pointer to the first node in the stack/queue
 * @line_number: Line number in the bytecode file that contains the opcode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = args[1];

	push_stack(stack, line_number, arg);
}

/**
 * check_int_arg - Checks if arg is an integer
 * @stack: Pointer to pointer to the first element in stack/queue
 * @line_number: Line number from the bytecode file
 * @arg: Argument to check
 *
 * Return: void
 */
void check_int_arg(unsigned int line_number, char *arg)
{
    int i;

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (i = 0; arg[i]; i++)
    {
        if (i == 0 && arg[i] == '-')
            continue;
        if (arg[i] < 48 || arg[i] > 57)
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
		}
	}
}

/**
 * push - Adds a new node at the top of stack/ back of a queue
 * @stack: Pointer to pointer to the first node in the stack/queue
 * @line_number: Line number in the bytecode file that contains the opcode
 * @arg: Argument to push to stack/queue
 *
 * Return: void
 */
void push_stack(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new, *temp;

    check_int_arg(line_number, arg);

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = atoi(arg);
    new->next = NULL;
    new->prev = NULL;

    if (*stack == NULL)
    {
        *stack = malloc(sizeof(stack_t));
        if (*stack == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        *stack = new;
    }
    else
    {
        temp = *stack;
        *stack = new;
        (*stack)->next = temp;
        temp->prev = *stack;
    }

}

/**
 * push - Adds a new node at the top of stack/ back of a queue
 * @stack: Pointer to pointer to the first node in the stack/queue
 * @line_number: Line number in the bytecode file that contains the opcode
 * @arg: Argument to push to stack/queue
 *
 * Return: void
 */
void push_queue(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new, *temp;

    check_int_arg(line_number, arg);

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = atoi(arg);
    new->next = NULL;
    new->prev = NULL;

    if (*stack == NULL)
    {
        *stack = malloc(sizeof(stack_t));
        if (*stack == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        *stack = new;
    }
    else
    {
        temp = *stack;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}
