#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int _putchar(char c);

int handle_string(char *str);
int len_num(int num);
int handle_number(int num);
int handle_binary(unsigned int num);

int _printf(const char *format, ...);

#endif /* MAIN_H */