#include "monty.h"

void sub(stack_t **head, unsigned int counter)
{
    stack_t *temp;
    int number = 0;
    if ((*head)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short", counter);
        exit(EXIT_FAILURE);
    }
    number = number + (*head)->n;
    temp = (*head)->next;
    temp->n = temp->n - number;
    (*head) = temp;
}
void mul(stack_t **head, unsigned int counter)
{
    stack_t *temp;
    int number = 0;
    if ((*head)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short", counter);
        exit(EXIT_FAILURE);
    }
    number = number + (*head)->n;
    temp = (*head)->next;
    temp->n = temp->n * number;
    (*head) = temp;
}
void pchar(stack_t **head, unsigned int counter)
{
    int number = (*head)->n;
    if ((*head) == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty", counter);
        exit(EXIT_FAILURE);
    }
    else if ((number < 0) || (number > 127))
    {
        fprintf(stderr, "L%u: can't pchar, value out of range", counter);
        exit(EXIT_FAILURE);
    }
    
    printf("%c\n", number);
}
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp = (*head);
	if ((*head) == NULL)
	{
		return;
	}
	while ((temp != NULL) && (temp->n != 0) && ((temp->n > 0) && (temp->n < 127)))
	{
		int number = temp->n;
        if (temp == NULL)
        {
            fprintf(stderr, "L%u: can't pchar, stack empty", counter);
            exit(EXIT_FAILURE);
        }
        else if ((number < 0) || (number > 127))
        {
            fprintf(stderr, "L%u: can't pchar, value out of range", counter);
            exit(EXIT_FAILURE);
        }
        printf("%c", number);
		temp = temp->next;
	}
    printf("\n");
}
