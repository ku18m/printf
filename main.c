#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *str = "Hi_first";

	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%s, %c, %v]\n", str, 'M');
	printf("Length:[%s, %c, %v]\n", str, 'M');
	return (0);
}