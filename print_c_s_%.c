#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
* print - print a char.
* @s: char to be printed..
* Return: 1.
*/
int print(char s)
{
	return (write(1, &s, 1));
}

/**
  * pr_chr - print fornatted char.
  * @args: parameter of type va_list to be printed.
  * Return: 1.
 */
int pr_chr(va_list args)
{
	char s = va_arg(args, int);

	return (print(s));
}

/**
  * pr_string - print formatted string.
  * @args: string to be printed..
  * Return: number of chars printed.
 */
int pr_string(va_list args)
{
	char *str = va_arg(args, char *);
	int sum = 0, j;
	char s;

	for (j = 0; j < (int)strlen(str); j++)
	{
		s = str[j];
		sum += print(s);
	}
	return (sum);
}

/**
 * _printf - whatever passed.
 * @format: chars to be printed.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	char p = '%', s;
	int sum = 0, i = 0;
	va_list args;

	va_start(args, format);
	if ((int)strlen(format) == 0)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += print(format[i]);
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				s = p;
				sum += print(s);
			}
			else if (format[i + 1] == 'c')
			{
				sum += pr_chr(args);
			}
			else if (format[i + 1] == 's')
			{
				sum += (pr_string(args));
			}
			i += 2;
		}
	}
	va_end(args);
	return (sum);
}
