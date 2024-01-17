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
    fclose(file);
    return (0);
}
