#include <stdio.h>
#include "main.h"

/**
 * print_handler - looks for the flag's funtion.
 *
 * @c: the flag to look for it's function.
 *
 * Return: the correct function OR (NULL) if not found.
 */
int (*print_handler(char c))(va_list)
{
	int i;
	printfuncs printfun[] = {
		{'c', print_c},
		{'s', print_s},
		{'i', print_i},
		{'d', print_i},
		{'\0', NULL}
	};

	i = 0;
	while (printfun[i].flag)
	{
		if (c == printfun[i].flag)
		{
			return (printfun[i].func);
		}
		i++;
	}
	return (NULL);
}
