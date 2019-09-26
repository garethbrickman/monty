#include "monty.h"
/**
 * strdigit - function checks if string contains numeric digits
 *
 * @str: char * to input string
 *
 * Return: 1 if string has numeric digits, 0 if it doesn't
 */

int strdigit(char *str)
{
	char *copy = str;
	int i = 0;

	if (copy[i] == '-')
		i = 1;
	while (copy[i] != '\0')
	{
		if (!isdigit(copy[i]))
			return (0);
		i++;
	}
	return (1);
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
