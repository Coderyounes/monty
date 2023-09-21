#include "monty.h"
taxi_t Taxi = {NULL, NULL};
/**
 * main - Entry point
 *
 * @argc: number of argument
 *
 * @argv: argument vector
 *
 * Return: failure status if it fails,otherwise Performe some operations
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t buffer = BUFF;
	FILE *file = NULL;
	unsigned int counter = 0;
	char *op = NULL;
	char *arg = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	Taxi.filehold = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &buffer, file) != -1)
	{
		op = tokenize(line, NULL);
		arg = tokenize(NULL, NULL);
		Taxi.arg = arg;

		if (op)
		{
			counter++;
			execute_instruction(op, &stack, counter);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
