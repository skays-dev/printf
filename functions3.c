#include "main.h"

/**
 * handle_hex_upper - Print the uppercase hexadecimal representation of an unsigned int
 * @num: The unsigned int to be printed in uppercase hexadecimal
 *
 * This function prints the uppercase hexadecimal representation of an unsigned int.
 * It converts the number to a string and prints it character by character.
 */
void handle_hex_upper(unsigned int num)
{
    int num_digits = len_hex_upper(num);
    char buffer[20];
    int index = num_digits - 1;
    int i;

    while (num > 0)
    {
        int remainder = num % 16;
        buffer[index] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        num /= 16;
        index--;
    }

    for (i = index + 1; i < num_digits; i++)
    {
        _putchar(buffer[i]);
    }
}


/**
 * len_hex_upper - Calculate the number of digits in the uppercase hexadecimal representation of an unsigned int
 * @num: The unsigned int for which to calculate uppercase hexadecimal length
 * Return: The number of digits in the uppercase hexadecimal representation
 *
 * This function calculates the number of digits in the uppercase hexadecimal representation of an unsigned int.
 */
int len_hex_upper(unsigned int num)
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
