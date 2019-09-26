#include "monty.h"

/**
 * get_op_func - function finds function for opcode
 *
 *@s: char * string of opcode
 *
 * Return: required function or NULL
 */

int (*get_op_func(char *s))(stack_t, unsigned int)
{

	instruction_t ops[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
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
