#include "monty.h"
/**
 * strdigit - function checks if string contains numeric digits
 *
 * @c: char input
 *
 * Return: 1 if string has numeric digits, 0 if it doesn't
 */
int strdigit(char *str)
{
    char *copy = str;
    int i = 0;
    while (copy[i] != '\0')
    {
        if (!isdigit(copy[i]))
            return (0);
        i++;
    }
    return (1);
}