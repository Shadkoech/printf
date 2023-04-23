#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_int(va_list arg_list);
int print_hexlower(unsigned int a, int b);
int print_hexupper(unsigned int num);
int _putchar(char c);


int print_char(va_list ap);
int print_string(va_list ap);



#endif
