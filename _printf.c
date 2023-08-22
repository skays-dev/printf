#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string containing format specifiers
 * @...: The variable number of arguments to format and print
 * Return: The total number of characters printed
 *
 * This function implements a subset of the printf function's functionality.
 * It processes the format string and any additional arguments provided
 * using the provided format specifiers. It supports the following format
 * specifiers: %c, %s, %S, %%, %d, and %i. Any other characters are printed
 * as-is. The function returns the total number of characters printed.
 */
int _printf(const char *format, ...)
{
int count = 0;
int i = 0;
va_list args;

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
count = swapShift(args, count, &i, format);
}
else
{
_putchar(format[i]);
count++;
}
i++;
}

va_end(args);

return (count);
}

/**
 * swapShift - Process a conversion specifier in printf format
 * @args: Args list for values
 * @count: Curr. char count (updated)
 * @i: Curr. char index (updated)
 * @str: Printf format string
 * Return: Updated count after processing specifier
 *
 * This function handles a specifier in printf format. Using
 * char at index `i` in `str`, it extracts data from `args`,
 * formats, and prints it. Updates `count` to track printed.
 */

int swapShift(va_list args, int count, int *i, const char *str)
{
switch (str[*i])
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;
case 's':
case 'S':
{
char *s = va_arg(args, char *);
count += handle_string(s);
}
break;
case '%':
_putchar('%');
count++;
break;
case 'd':
case 'i':
{
int number = va_arg(args, int);
if (number < 0)
count++;
count += len_num(number);
handle_number(number);
}
break;
default:
_putchar(str[*i - 1]);
_putchar(str[*i]);
count += 2;
break;
}
return (count);
}
