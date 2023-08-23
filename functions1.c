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
handle_string("(null)");
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

/**
 * handle_binary - Print the binary representation of an unsigned int
 * @num: The unsigned int to be printed in binary
 * Return: The number of characters printed
 */
int handle_binary(unsigned int num)
{
    int binary_length = 0;
    unsigned int temp = num;
    int count = 0; 

    while (temp > 0)
    {
        temp /= 2;
        binary_length++;
    }

    while (binary_length > 0)
    {
        int bit = (num >> (binary_length - 1)) & 1;
        _putchar(bit + '0');
        count++;
        binary_length--;
    }

    return count;
}

/**
 * handle_unsigned - Print the decimal representation of an unsigned int
 * @num: The unsigned int to be printed
 *
 * This function prints the decimal representation of an unsigned int.
 * It converts the number to a string and prints it character by character.
 */
void handle_unsigned(unsigned int num)
{
    char buffer[20];
    int index = 0;
    int i;

    if (num == 0)
    {
        _putchar('0');
        return;
    }

    while (num > 0)
    {
        buffer[index] = (num % 10) + '0';
        num /= 10;
        index++;
    }

    for (i = index - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
    }
}
