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

return count;
}

/**
 * swapShift - Process a single conversion specifier in the printf format string
 * @args: Argument list for extracting values
 * @count: Current character count (updated)
 * @i: Index of current character in the format string (updated)
 * @str: Printf format string
 * Return: Updated character count after processing specifier
 *
 * This function processes a conversion specifier encountered in printf format.
 * Using format char at index `i` in the input `str`, it extracts data from
 * `args` list, formats, and prints it. It updates `count` to track printed chars.
 *
 * Supported format specifiers:
 * - %c: Prints a character.
 * - %s: Prints a null-terminated string.
 * - %S: Prints a null-terminated string (same as %s).
 * - %%: Prints a literal percent character.
 * - %d: Prints an integer as a signed decimal number.
 * - %i: Prints an integer as a signed decimal number (same as %d).
 * - Default case: Prints unknown specifiers, increments `count` by 2.
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
return count;
}