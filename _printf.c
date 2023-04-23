#include "main.h"

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
	if (format == NULL)
		exit(-1)
	while (format[i] != '\0')
	{:wq
		if (format[i] != '%')
		{
			sum += print(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			sum += print('%');
		}
		else if (format[i + 1] == 'c')
		{
			sum += pr_chr(args);
		}
		else if (format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			if (str != NULL)
				sum += pr_string(str);
			else
				sum += pr_string("nil");
		}
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
