#include "main.h"

/**
 * pr_octal - prints an octal number from int
 * @args: number to be converted
 * Return: number of char printed
 */
int pr_octal(va_list args)
{
	int sum = 0;

	unsigned int o = va_arg(args, unsigned int);

	return (print_o(o, sum));
}
/**
 * print_o - converts int to octal
 * @n numbr o be converted
 * @sum: 0
 * Return: number of char
 */
int print_o(unsigned int n, int sum)
{
	unsigned int sum;
	int i, j;
	i = 1;

	for (j = n; j > 0; j /= 8)
	{
		sum += (j % 8) * i;
		i *= 10;
		n /= 8;
	}
	return (sum);
}
