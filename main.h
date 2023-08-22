#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * struct print_all - struct that contains flags & it's functions.
 *
 * @flag: the data type flag.
 * @func: the correct function to print the data type.
 *
*/
typedef struct print_all
{
	char flag;
	int (*func)(va_list args);
} printfuncs;
int _printf(const char *format, ...);
int (*print_handler(char c))(va_list);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
#endif
