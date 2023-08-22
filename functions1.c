#include "main.h"


/**
 * handle_string - Print each character of the input string and count characters printed
 * @str: The input string to be processed
 * Return: The total count of characters printed
 */
int handle_string(char *str)
{
int i = 0;
if (str == NULL)
{
handle_string('(null)');
return (i);
}
while (str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}

/**
 * len_num - Calculate the number of digits in a positive integer
 * @num: The input number
 * Return: The number of digits in the input number
 */
int len_num(int num)
{
if (num == 0)
return (0);
return (1 + len_num(num / 10));
}

/**
 * handle_number - Print an integer and count digits printed
 * @num: The integer to be printed
 * Return: The total count of digits printed
 */
int handle_number(int num)
{
if (num == -214783648)
{
_putchar('-');
_putchar('2');
handle_number(14783648);
return (1);
}
else if (num < 0)
{
_putchar('-');
num -= num;
}

if (num >= 10)
{
handle_number(num / 10);
handle_number(num % 10);
}
else if (num < 10)
{
_putchar(num + '0');
}
return (1);
}