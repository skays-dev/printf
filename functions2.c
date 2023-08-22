#include "main.h"

/**
 * len_num_unsigned - Calculate the number of digits in an unsigned int
 * @num: The unsigned int to be calculated
 * Return: The number of digits in the unsigned int
 *
 * This function calculates the number of digits in an unsigned int.
 */
int len_num_unsigned(unsigned int num)
{
    int count = 0;

    if (num == 0)
    {
        return 1; 
    }

    while (num > 0)
    {
        num /= 10;
        count++;
    }

    return count;
}

/**
 * handle_octal - Print the octal representation of an unsigned int
 * @num: The unsigned int to be printed in octal
 *
 * This function prints the octal representation of an unsigned int.
 * It converts the number to a string and prints it character by character.
 */
void handle_octal(unsigned int num)
{
    int num_digits = len_octal(num);
    char buffer[20]; 
    int index = num_digits - 1;

    while (num > 0)
    {
        buffer[index] = (num % 8) + '0';
        num /= 8;
        index--;
    }

    for (int i = index + 1; i < num_digits; i++)
    {
        _putchar(buffer[i]);
    }
}

/**
 * len_octal - Calculate the number of digits in the octal representation of an unsigned int
 * @num: The unsigned int for which to calculate octal length
 * Return: The number of digits in the octal representation
 *
 * This function calculates the number of digits in the octal representation of an unsigned int.
 */
int len_octal(unsigned int num)
{
    int count = 0;

    if (num == 0)
    {
        return 1;
    }

    while (num > 0)
    {
        num /= 8;
        count++;
    }

    return count;
}


/**
 * handle_hex_lower - Print the lowercase hexadecimal representation of an unsigned int
 * @num: The unsigned int to be printed in lowercase hexadecimal
 *
 * This function prints the lowercase hexadecimal representation of an unsigned int.
 * It converts the number to a string and prints it character by character.
 */
void handle_hex_lower(unsigned int num)
{
    int num_digits = len_hex_lower(num);
    char buffer[20]; 
    int index = num_digits - 1;

    while (num > 0)
    {
        int remainder = num % 16;
        buffer[index] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
        num /= 16;
        index--;
    }

    for (int i = index + 1; i < num_digits; i++)
    {
        _putchar(buffer[i]);
    }
}

/**
 * len_hex_lower - Calculate the number of digits in the lowercase hexadecimal representation of an unsigned int
 * @num: The unsigned int for which to calculate lowercase hexadecimal length
 * Return: The number of digits in the lowercase hexadecimal representation
 *
 * This function calculates the number of digits in the lowercase hexadecimal representation of an unsigned int.
 */
int len_hex_lower(unsigned int num)
{
    int count = 0;

    if (num == 0)
    {
        return 1;
    }

    while (num > 0)
    {
        num /= 16;
        count++;
    }

    return count;
}
