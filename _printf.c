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
_putchar(format[i]);
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
