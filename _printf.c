#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 *
 * @format: a string that holds the flags for the variables.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings), (-1) if it fails.
 */
int _printf(const char *format, ...)
{
	int i, count;
	int (*fun)(va_list);
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0, count = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0' || (format[i] == ' ' && format[i + 1] == '\0'))
			{
				va_end(args);
				return (-1);
			}
			else if (format[i] == '%')
				count += write(1, &format[i], 1);
			else
			{
				fun = print_handler(format[i]);
				if (fun == NULL)
					count += write(1, &format[i - 1], 1), count += write(1, &format[i], 1);
				else
					count += fun(args);
			}
			i++;
		}
		if (format[i] != '%' && format[i])
			count += write(1, &format[i], 1), i++;
	}
	va_end(args);
	return (count);
}
