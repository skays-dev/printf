#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

int _putchar(char c);

int handle_string(char *str);
int len_num(int num);
int handle_number(int num);
int handle_binary(unsigned int num);

void handle_unsigned(unsigned int num);
int len_num_unsigned(unsigned int num);
void handle_octal(unsigned int num);
int len_octal(unsigned int num);
void handle_hex_lower(unsigned int num);
int len_hex_lower(unsigned int num);
void handle_hex_upper(unsigned int num);
int len_hex_upper(unsigned int num);


int _printf(const char *format, ...);

#endif /* MAIN_H */