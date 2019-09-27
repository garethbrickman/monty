#include "monty.h"

/**
 * sub - function subtracts top of the stack from second top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if (((*head)->next == NULL) || ((*head) == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	number = number + (*head)->n;
	temp = (*head)->next;
	temp->n = temp->n - number;
	(*head) = temp;
}

/**
 * mul - function multiplies second top of the stack with top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if (((*head)->next == NULL) || ((*head) == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	number = number + (*head)->n;
	temp = (*head)->next;
	temp->n = temp->n * number;
	(*head) = temp;
}

/**
 * pchar - function prints char at top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void pchar(stack_t **head, unsigned int counter)
{
	int number = (*head)->n;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	else if ((number < 0) || (number > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", number);
}
/**
 * pstr - function prints char at top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp = (*head);
	int number;

	if ((*head) == NULL)
	{
		return;
	}
	while ((temp != NULL) && (temp->n != 0) && ((temp->n > 0) && (temp->n < 127)))
	{
		number = temp->n;
		if (temp == NULL)
		{
			fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
			exit(EXIT_FAILURE);
		}
		else if ((number < 0) || (number > 127))
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
			exit(EXIT_FAILURE);
		}
		printf("%c", number);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * swap - function multiplies second top of the stack with top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void swap(stack_t **head, unsigned int counter)
{
	int number1;
	int number2;

	if (((*head)->next == NULL) || ((*head) == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	number1 = (*head)->n;
	(*head) = (*head)->next;
	number2 = (*head)->n;
	(*head)->n = number1;
	(*head) = (*head)->prev;
	(*head)->n = number2;
}
