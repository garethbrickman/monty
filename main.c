#include "monty.h"
stack_t *head = NULL;

/**
 * main - function to run monty files
 *
 * @argc: int number of args
 * @argv: char const * to args
 *
 * Return: 0
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

/**
 * execute - function to execute functions according to opcode
 *
 * @opcode: char * to opcode string
 * @counter: int line number
 * @data: char * to data for stack_t int n
 *
 * Return: 1 if string has numeric digits, 0 if it doesn't
 */

void execute(char *opcode, unsigned int counter, char *data)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = get_op_func(opcode);
	if (strcmp(opcode, "push") == 0)
	{
		if (strdigit(data) != 1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", counter);
			exit(EXIT_FAILURE);
		}
		add_dnodeint(&head, atoi(data));
	}
	else if (f != NULL)
		(f(&head, counter));
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
		exit(EXIT_FAILURE);
	}
/* get_op_func(opcode)(&head, counter); */
/*   else if (strcmp(opcode, "pall") == 0) */
/*   { */
/*   print_dlistint(&head, counter); */
/*   } */
/*   else if (strcmp(opcode, "pint") == 0) */
/*   { */
/*   pint(&head, counter); */
/*   } */
/*   else if (strcmp(opcode, "pop") == 0) */
/*   { */
/*   pop(&head, counter); */
/*   } */
/*   else if (strcmp(opcode, "add") == 0) */
/*   { */
/*   add(&head, counter); */
/*   } */
}

/**
 * freestack - function frees stack_t linked list
 *
 * Return: void
 */
void freestack(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	tmp = head;
	head = head->next;
	free(tmp);
}
