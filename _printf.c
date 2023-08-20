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
	int i, o, count;
	printfuncs printf[] = {
		{'c', print_c},
		{'s', print_s},
		{'\0', NULL}};
	va_list args;

	va_start(args, format);
	i = 0, count = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else if (format[i] == '%')
			{
				count += write(1, &format[i], 1);
			}
			else
			{
				o = 0;
				while (printf[o].flag != '\0')
				{
					if (printf[o].flag == format[i])
					{
						count += printf[o].func(args);
						break;
					}
					o++;
				}
				if (o == 2)
				{
					count += write(1, &format[i - 1], 1), count += write(1, &format[i], 1);
				}
			}
			i++;
		}
		count += write(1, &format[i], 1), i++;
	}
	va_end(args);
	return (count);
}
