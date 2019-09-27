#include "monty.h"

/**
 * get_op_func - function finds function for opcode
 *
 *@s: char * string of opcode
 *
 * Return: apropriate function or NULL
 */

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"pall", print_dlistint},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"swap", swap},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (!strcmp(s, ops[i].opcode))
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
