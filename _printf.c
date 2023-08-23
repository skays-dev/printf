#include "main.h"
#include <stdarg.h>

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
(*i)++;
switch (str[*i])
{
case 'u':
{
unsigned int num = va_arg(args, unsigned int);
count += len_num_unsigned(num);
unsigned int handle_unsigned(num);
}
break;
case 'o':
{
unsigned int number = va_arg(args, unsigned int);
count += len_octal(number);
handle_octal(number);
}
break;
case '+':
{
int num = va_arg(args, int);
if (num >= 0)
{
count += _putchar("+");
}
handle_number(num);
}
break;
case 'x':
{
unsigned int number = va_arg(args, unsigned int);
count += len_hex_lower(number);
handle_hex_lower(number);
}
break;
case '#':
{
int num = va_arg(args, int);
if (str[*i - 1] == 'o')
{
count += _putchar("0");
}
else if (str[*i - 1] == 'x' || str[*i - 1] == 'X')
{
count += _putchar("0");
count += _putchar(str + (*i - 1));
}
handle_number(num);
}
break;
case ' ':
{
int num = va_arg(args, int);
if (num >= 0)
{
count += _putchar(" ");
}
handle_number(num);
}
break;
case 'X':
{
unsigned int number = va_arg(args, unsigned int);
count += len_hex_upper(number);
handle_hex_upper(number);
}
break;
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
case 'p':
{
void *ptr = va_arg(args, void *);
unsigned long ptr_value = (unsigned long)ptr;
count += len_hex_lower(ptr_value);
handle_hex_lower(ptr_value);
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
case 'b':
{
unsigned int number = va_arg(args, unsigned int);
count += handle_binary(number);
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
