#include "monty.h"
stack_t *head = NULL;

/**
 * main - function to run monty files
 *
 * @argc: int number of args
 * @argv: char const * to args
 *
 * Return: 00
 */

int main(int argc, char const *argv[])
{
	FILE *fp;
	char *linestr = NULL;
	char *opcode = NULL;
	char *strtok_address = NULL;
	char *data;
	size_t n;
	ssize_t charsprinted;
	unsigned int counter = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((charsprinted = getline(&linestr, &n, fp)) != -1)
	{
		strtok_address = linestr;
		linestr = strtok(linestr, "\n");
		opcode = strtok(linestr, " ");
		data = strtok(NULL, " ");

		if (opcode)
			execute(opcode, counter, data);
		counter++;
	}
	fclose(fp);
	free(strtok_address);
	freestack();
	return (0);
}
