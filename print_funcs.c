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
	if (c == NULL)
	{
		c = "(null)";
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_i - prints integers.
 *
 * @args: a va_list that holds the variables.
 *
 * Return: the number of characters printed.
 */
int print_i(va_list args)
{
	int temp, num, i, digits = 0;
	char *str;

	num = va_arg(args, int), temp = num;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		while (temp != 0)
			temp /= 10, digits++;
	}
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (num < 0)
	{
		num = num * -1;
		str = (char *)malloc((digits + 2) * sizeof(char));
		str[0] = '-';
		digits++, str[digits] = '\0';
	}
	else
	{
		str[digits] = '\0';
	}
	while (num != 0)
	{
		digits--, str[digits] = (char)((num % 10) + '0');
		num /= 10;
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1), i++;
	}
	free(str);
	return (i);
}
