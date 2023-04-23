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
	int index = 0;

	va_start(ap, format);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				index = index + _putchar(va_arg(ap, int));
				break;
				case 's':
				index = index + printf("%s", va_arg(ap, char *));
				break;
				case '%':
				index = index + _putchar('%');
				break;
			}
		}
		else
		{
			index = index + _putchar(*format);
		}
	}

	va_end(ap);
	
	return index;
}
