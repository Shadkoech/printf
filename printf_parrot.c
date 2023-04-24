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
	int num = va_arg(ap, int);

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
					index = index + _putchar(*va_arg(ap, char *));
					break;
				case 'c':
					index = index + _putchar(va_arg(ap, int));
					break;
				case 'd':
				case 'i':
					index = index + print_integer(&num);
					break;
				case '%':
					index = index + print_percentage();
					break;
				default:
					index = index + _putchar(format[x]);
					index = index + print_actual();
					break;
			}
		}
		else
			index = index + _putchar(format[x]);
	}
	va_end(ap);
	return (index);
}
