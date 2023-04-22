#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
* print - print a char.
* @s: parameter of type va_list .
* Return: 1.
*/
int print(char s)
{
	return (write(1, &s, 1));
}

/**
 * _printf - print whatever passed.
 * @format: number of argument passed.
 * Return: number of character printed.
 */

int _printf(const char *format, ...)
{
	char p = '%', s, *str;
	int sum = 0, i = 0, j;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += print(format[i]);
		}
		else
		{
			if (format[i + 1] == '%')
			{
				s = p;
				sum += print(s);
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				s = va_arg(args, int);
				sum += print(s);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				for (j = 0; j < (int)strlen(str); j++)
				{
					s = str[j];
					sum += print(s);
				}
				i++;
			}
		}
		i++;
	}
	va_end(args);
	return (sum);
}
