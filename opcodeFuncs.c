#include "monty.h"
/**
 * print_dlistint - function prints all elements of dlistint_t list
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: nothing
 */
void print_dlistint(stack_t **head, unsigned int counter)
{
	int x;
	stack_t *temp = (*head);
	(void)counter;

	if ((*head) == NULL)
		return;
	for (x = 0; temp != NULL; x++)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}

/**
 * *add_dnodeint - function adds new node to beginning of list
 *
 *@head: pointer to pointer of head of linked list
 *@n: const int pointer
 *
 * Return: nothing
 */
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *newhead = NULL;

	newhead = malloc(sizeof(stack_t));
	if (newhead == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newhead->n = n;
	newhead->next = (*head);
	newhead->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = newhead;
	(*head) = newhead;
}

/**
 * pint - function prints value at the top of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: nothing
 */

void pint(stack_t **head, unsigned int counter)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*head)->n);
}

/**
 * pop - function removes the top element of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: nothing
 */

void pop(stack_t **head, unsigned int counter)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
}

/**
 * add - function adds the top two elements of the stack
 *
 *@head: double pointer to head of linked list
 *@counter: unsigned int for line counter
 *
 * Return: void
 */

void add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if (((*head)->next == NULL) || ((*head) == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	number = number + (*head)->n;
	temp = (*head)->next;
	temp->n = temp->n + number;
	(*head) = temp;
}
