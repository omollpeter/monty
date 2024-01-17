#include "monty.h"

/**
 * main - Checks code
 * @ac: Number of program parameters
 * @av: Array of the program parameters
 *
 * Return: 0 (Always success)
 */
int main(int ac, char **av)
{
	stack_t *stack;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read_bytecode(file, &stack);
	free(stack);
	fclose(file);
	return (0);
}
/**
 * free_stack - frees the stack
 * @stack: points to the pointer stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp, *del;

	temp = stack;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
}
/**
 * free_arr_str - frees array of strings
 * @str: array to free
 *
 * Return: void
 */
void free_arr_str(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
