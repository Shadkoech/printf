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
	int x = 0;
	int index = 0;

	va_start(ap, format);

	while (format && format[x])
	{
		if (format[x] == '%')
		{
			x++;
			if (format[x] != '\0')
				break;

			switch (format[x])
			{
				case 's':
					index = index + _putchar(va_arg(ap, char*));
					break;
				case 'c':
					index = index + _putchar(va_arg(ap, int));
				case 'i':
					index = index + print_integer(va_arg(ap, int));
				case 'x':
					index = index + print_hexlower(va_arg(ap, unsigned int), 0);
				case 'X':
					index = index + print_hexupper(va_arg(ap, unsigned int));
				default:
					index = index + _putchar('%');
					index = index + _putchar(format[x]);
					break;
			}
		}
		else
			index = index + _putchar(format[x]);
	}

	va_end(ap);

	return (index);
}
