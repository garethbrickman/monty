#include "monty.h"
/**
 * print_dlistint - function prints all elements of dlistint_t list
 *
 *@h: pointer to head of linked list
 *
 * Return: number of nodes
 */
void print_dlistint(stack_t **head, unsigned int counter)
{
	int x;
	stack_t *temp = (*head);
	(void)counter;

	if ((*head) == NULL)
	{
		return;
	}
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
 * Return: address of new element, or NULL if failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
    stack_t *newhead = NULL;
    newhead = malloc(sizeof(stack_t));
    if (newhead == NULL)
        return (NULL);
    newhead->n = n;
    newhead->next = (*head);
    newhead->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = newhead;
    (*head) = newhead;
    return (newhead);
}

void pint(stack_t **head, unsigned int counter)
{
    if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

    printf("%i\n", (*head)->n);
}

void pop(stack_t **head, unsigned int counter)
{
    if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}

    (*head) = (*head)->next;
}

void add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int number = 0;

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", counter);
		exit(EXIT_FAILURE);
	}

	number = number + (*head)->n;
	temp = (*head)->next;
	temp->n = temp->n + number;
	(*head) = temp;
}
