#include "main.h"


/**
  *_printf - A function that produces a certain output in line with a format
  *@format:  a pointer to the string with the format that has characters
  *
  *Return: characters to be printed
  */
int _printf(const char *format, ...)
{
	va_list ap;
	char c;
	int index = 0;

	va_start(ap, format);
	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			if (*format++ == 'c')
				index = index + print_char(ap);
			if (*format++ == 's')
				index = index + print_string(ap);
			if (*format++ == '%')
			{
				_putchar('%');
				index++;
			}
		}
		else
		{
			_putchar(c);
			index++;
		}
	}
	va_end(ap);
	return (index);
}
