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
  * @str: string to be printed..
  * Return: number of chars printed.
 */
int pr_string(char *str)
{
	int sum = 0, j;
	char s;
	int len = (int)strlen(str);

	for (j = 0; j < len; j++)
	{
		s = str[j];
		sum += print(s);
	}
	return (sum);
}
/**
 * print_buffer - create a buffer
 * @str: string to be stored.
 * Return: number of chars printed
 */
int print_buffer(char *str)
{
	char buffer[1024];
	int i = 0, sum = 0;
	int len = (int)strlen(str);

	for (i = 0; i < len; i++)
	{
		if (i <= 1024)
			buffer[i] = str[i];
	}
	sum += write(1, buffer, len);
	return (sum);
}
