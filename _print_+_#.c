#include "main.h"
/**
*pr_flag - print the flags
 * @flag: flag to be added
 * @args: argument to be formatted.
 * Return: number of chars printed.
 */

int pr_flag(char flag, va_list args)
{
	int sum = 0;

	if (flag == '+')
		sum += pr_sign(args);
	if (flag == ' ')
		sum += pr_space(args);
	return (sum);
}

/**
 * pr_space - print a space before + numbers.
 * @args: number.
 * Return: 0, 1.
 */

int pr_space(va_list args)
{
	int sum = 0;

	if (va_arg(args, long int) > 0)
		sum += print (' ');
	return (sum);
}
/**
 * pr_sign - print a sign before the number.
 * @args: the number to be printed.
 * Return: number of chars printed.
 */

int pr_sign(va_list args)
{
	int sum = 0;

	if (va_arg(args, long int) > 0)
		sum += print('+');
	return (sum);
}

/**
 * pr_format - format octal and hexa numbers
 * @f: o, x, X.
 * Return: number of chars printed.
 */
int pr_format(char f)
{
	int sum = 0;

	if (f == 'o')
		sum += print('0');
	else if (f == 'x')
	{
		sum += print('0');
		sum += print('x');
	}
	else if (f == 'X')
	{
		sum += print('0');
		sum += print('X');
	}
	return (sum);
}
