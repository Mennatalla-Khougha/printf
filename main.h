#ifndef _MAIN_H_
#define _MAIN_H_
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int pr_chr(va_list args);
int pr_string(char *str);
int pr_percent(void);
int print(char s);
int check_input(const char *format);
/**
* struct op - Struct op
*
* @op: The operator
* @f: The function associated
*/
typedef struct ch
{
char ch;
int (*ptr)(va_list args);
} ch_t;
int _printf(const char *format, ...);
#endif
