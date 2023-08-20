#include <stdio.h>
#include "main.h"

/**
 * print_c - produces output according to a format.
 *
 * @args: a va_list that holds the variables.
 *
 * Return: the number of characters printed.
 */
int print_c(va_list args)
{
	int i = 0;
	char c;

	c = va_arg(args, int);
	i += write(1, &c, 1);
	return (i);
}

/**
 * print_s - produces output according to a format.
 *
 * @args: a va_list that holds the variables.
 *
 * Return: the number of characters printed.
 */
int print_s(va_list args)
{
	char *c;
	int i = 0;

	c = va_arg(args, char *);
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}
