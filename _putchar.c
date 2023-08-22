#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write a character to the standard output (stdout)
 * @c: The character to be written
 * Return: On success, returns the number of characters written (1)
 *
 * This function writes a single character to the standard output (stdout)
 * using the `write` system call. It takes a character as input and writes
 * it to the standard output file descriptor (file descriptor 1). The return
 * value indicates the number of characters successfully written, which is
 * always 1 in this case.
 *
 * Note: The function is used to provide a custom implementation of the
 *       standard C library's putchar function.
 */

int _putchar(char c){
return (write(1, &c, 1));
}
