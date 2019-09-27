#include "monty.h"
/**
 * execute - function to execute functions according to opcode
 *
 * @opcode: char * to opcode string
 * @counter: int line number
 * @data: char * to data for stack_t int n
 *
 * Return: Nothing
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
}
