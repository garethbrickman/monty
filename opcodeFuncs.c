#include "monty.h"
/**
 * print_dlistint - function prints all elements of dlistint_t list
 *
 *@h: pointer to head of linked list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
    int x;
    //printf("test");
    for (x = 0; h != NULL; x++)
    {
        printf("%i\n", h->n);
        h = h->next;
    }
    return (x);
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

stack_t *pint(stack_t *head)
{
    printf("%i\n", head->n);
}

stack_t *pop(stack_t **head)
{
    (*head) = (*head)->next;
}