#include "main.h"
#include <stdarg.h>

/**
 * handle_conversion - Handles a specific conversion specifier in printf format
 * @args: Args list for values
 * @count: Curr. char count (updated)
 * @specifier: The conversion specifier to handle
 * Return: Updated count after processing specifier
 *
 * This function processes a specific conversion specifier in printf format,
 * extracting data from `args`, formatting, and printing it based on the
 * provided conversion specifier. It supports various conversion specifiers
 * including 'u', 'o', 'x', 'X', 'c', 's', 'S', 'p', '%', 'd', 'i', and 'b'.
 * The function returns the updated character count after processing.
 */
int handle_conversion(va_list args, int count, char specifier)
{
switch (specifier)
{
case 'u': count = unsigned int handle_unsigned(args, count); break;
case 'o': count = handle_octal(args, count); break;
case 'x': count = handle_hex_lower(args, count); break;
case 'X': count = handle_hex_upper(args, count); break;
case 'c': _putchar(va_arg(args, int)); count++; break;
case 's':
case 'S': count += handle_string(args, count); break;
case 'p': count += handle_pointer(args, count); break;
case '%': _putchar('%'); count++; break;
case 'd':
case 'i': count = handle_decimal(args, count); break;
case 'b': count = handle_binary(args, count); break;
default:
_putchar(str[*i - 1]);
_putchar(str[*i]);
count += 2;
break;
}
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
 * char at index `i` in `str`, it extracts the conversion specifier,
 * and delegates the processing to the appropriate handler using
 * the `handle_conversion` function. Updates `count` to track printed.
 */
int swapShift(va_list args, int count, int *i, const char *str)
{
(*i)++;
char specifier = str[*i];
count = handle_conversion(args, count, specifier);
return (count);
}

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

char buffer[BUFFER_SIZE];
int buffer_index = 0;

va_start(args, format);

while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
count = swapShift(args, count, &i, format);
}
else
{
if (buffer_index >= BUFFER_SIZE)
{
write(1, buffer, buffer_index);
buffer_index = 0;
}
buffer[buffer_index++] = format[i];
count++;
}
i++;
}

if (buffer_index > 0)
{
write(1, buffer, buffer_index);
}

va_end(args);

return (count);
}
