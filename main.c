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
	/*char *str = "Hi_first";*/
	int i;

	/*_printf("Let's try to printf a simple sentence.\n");*/
	/*printf("Let's try to printf a simple sentence.\n");*/
	i = _printf("%%%", NULL, 'c');
	/*o = _printf("%%");*/
	/*o = printf("%s", NULL);*/
	printf("\n%d\n", i);
	return (0);
}