#include "main.h"

/**
 * pr_binary - prints a binary number from int
 * @args: number to be converted
 * Return: number of char printed
 */
int pr_binary(va_list args)
{
	int sum = 0;

	unsigned int b = va_arg(args, unsigned int);

	return (print_b(b, sum));
}
/**
 * print_b - convert int to binary
 * @n: number to be converted
 * @sum: 0
 * Return: number of char printed
 */
int print_b(int n, int sum)
{
	unsigned int x = n;

	x /= 2;

	if (x != 0)
		sum = print_b(x, sum);
	sum += print('0' + n % 2);
	return (sum);
}
