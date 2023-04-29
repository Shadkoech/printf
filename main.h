#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_int(va_list arg_list);
int print_hexlower(unsigned int a, int b);
int print_hexupper(unsigned int num);
int _putchar(char c);
void print_unsigned_integer(unsigned int n);
void custom_convert(char *format, ...);
int change_to_string(int i, char *buffer);
char *change_unsigned_int_to_binary(unsigned int number);
void print_unsigned_octal(unsigned int n);
void print_hexadecimal(unsigned int n, int UPPER);
void print_unsigned_integer(unsigned int n);
int print_char(va_list ap);
int print_string(va_list ap);

#endif
