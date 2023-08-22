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
	int temp, num, digits = 0, isNegative = 0;
	char *str;

	num = va_arg(args, int);
	if (num == 0 || !num)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = num;
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	else
		while (temp != 0)
			temp /= 10, digits++;
	str = (char *)malloc((digits + isNegative + 1) * sizeof(char));
	str[digits + isNegative] = '\0';
	if (isNegative)
		str[0] = '-';
	while (num != 0)
	{
		digits--, str[digits + isNegative] = (char)((num % 10) + '0');
		num /= 10;
	}
	temp = 0;
	while (str[temp])
	{
		write(1, &str[temp], 1);
		temp++;
	}
	free(str);
	return (temp);
}

/**
 * print_b - prints integers in binary.
 *
 * @args: a va_list that holds the variables.
 *
 * Return: the number of characters printed.
 */
int print_b(va_list args)
{
	unsigned int num, i, o;
	char bin[32];

	num = va_arg(args, int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (num > 0)
	{
		bin[i] = (num % 2) + 48;
		num = num / 2;
		i++;
	}
	o = i;
	while (i != 0)
	{
		i--;
		write(1, &bin[i], 1);
	}
	return (o);
}
