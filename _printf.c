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
 * @args: The argument list to extract values from
 * @count: The current character count (updated by the function)
 * @i: The index of the current character in the format string (updated by the function)
 * @str: The printf format string
 * Return: The updated character count after processing the conversion specifier
 *
 * This function processes a single conversion specifier encountered in the printf
 * format string. It uses the format specifier character at index `i` in the input
 * format string `str` to determine the type of data to retrieve from the argument
 * list `args`, and then formats and prints it accordingly. The function updates the
 * `count` to track the total number of characters printed.
 *
 * The following format specifiers are supported:
 * - %c: Prints a single character.
 * - %s: Prints a null-terminated string.
 * - %S: Prints a null-terminated string (same as %s).
 * - %%: Prints a literal percent character.
 * - %d: Prints an integer as a signed decimal number.
 * - %i: Prints an integer as a signed decimal number (same as %d).
 * - Default case: Prints unknown format specifiers and increments `count` by 2.
 */
int swapShift(va_list args, int count, int *i, const char *str)
{
switch (str[*i])
{
case 'c': // %c
_putchar(va_arg(args, int));
count++;
break;
case 's': // %s
case 'S': // %s (same behavior)
{
char *s = va_arg(args, char *);
count += handle_string(s);
}
break;
case '%': // %%
_putchar('%');
count++;
break;
case 'd': // %d or %i
case 'i':
{
int number = va_arg(args, int);
if (number < 0)
count++;
count += len_num(number);
handle_number(number);
}
break;
default: // %unknown
_putchar(str[*i - 1]);
_putchar(str[*i]);
count += 2;
break;
}
return count;
}