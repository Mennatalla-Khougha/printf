#include "main.h"

/**
 * check_input - check the input of _printf.
 * @format: string to be checked.
 * Return: 0;
 */

int check_input(const char *format)
{
	if (format == NULL)
		exit(-1);
	if (!strlen(format))
		return (1);
	else
		return (0);
}
/**
 * _printf - print whatever passed.
 * @format: chars to be printed.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	int sum = 0, i = 0;
	char *str;
	va_list args;

	va_start(args, format);
	if (check_input(format))
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += print(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == '%')
			sum += print('%');
		else if (format[i + 1] == 'c')
			sum += pr_chr(args);
		else if (format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			if (str != NULL)
				sum += pr_string(str);
			else
				sum += pr_string("(null)");
		}
		else if (format[i + 1] == '\0')
			return (-1);
		else
		{
			sum += print(format[i]);
			sum += print(format[i + 1]);
		}
		i += 2;
	}
	va_end(args);
	return (sum);
}
