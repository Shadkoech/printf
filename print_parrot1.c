#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
  *custom_convert - function that checks input string
  *@format: pointer to char string
  *Return: nothing
  */
void custom_convert(char *format, ...)
{
	char *c = format;
	va_list ap;

	va_start(ap, format);

	while (*c)
	{
		if (*c == '%' && *(c + 1) == 'S')
		{
			char *str = va_arg(ap, char*);
			char *b = str;

			while (*b)
			{
				if (*b >= 32 && *b < 127)
				{
					putchar(*b);
				}
				else
				{
					putchar('\\');
					putchar('x');
					putchar("0123456789ABCDEF"[(*b >> 4) & 0xF]);
					putchar("0123456789ABCDEF"[*b & 0xF]);
				}
				b++;
			}
			c = c + 2;
		}
		else
		{
			putchar(*c++);
		}
	}
	va_end(ap);
}


/**
  *change_to_string - converts integer to string
  *@i: integer to be changed
  *@buffer: pointer to store converted string
  *Return: Always 0
  */
int change_to_string(int i, char *buffer);
char *change_unsigned_int_to_binary(unsigned int number);

/**
  *change_unsigned_int_to_binary -function that takes convert integer to string
  *@number: the integer to be converted
  *
  *Return: a pointer to character array
  */
char *change_unsigned_int_to_binary(unsigned int number)
{
	char *binary = (char *)malloc(sizeof(char) * 33);
	int j = 0;
	int found_one = 0;

	if (binary == NULL)
	{
		return (NULL);
	}
	for (j = 31; j >= 0; j--)
	{
		if ((number & (1 << j)) || found_one)
		{
			binary[31 - j] = (number & (1 << j)) ? '1' : '0';
			found_one = 1;
		}
		else if (!(number & (1 << j)) && !found_one)
		{
			binary[31 - j] = ' ';
		}
	}
	binary[32] = '\0';
	return (binary);
}

/**
  *change_to_string - converts a given integer into string
  *@i: the integer to be converted
  *@buffer: a pointer to where the converted integer is stored
  *
  *Return: Always 0
  */
int change_to_string(int i, char *buffer)
{
	bool is_num_neg = false;
	int length = 0, j = 0;

	if (i < 0)
	{
		is_num_neg = true;
		i = -i;
	}
	do {
		buffer[length++] = (i % 10) + '0';
		i /= 10;
	} while (i > 0);

	if (is_num_neg)
	{
		buffer[length++] = '-';
	}
	for (j = 0; j < (length / 2); j++)
	{
		char tmp = buffer[j];

		buffer[j] = buffer[length - j - 1];
		buffer[length - j - 1] = tmp;
	}
	return (length);
}

/**
  *_putchar - a function that writes a character to stdio
  *@c: the character to be written
  *
  *Return: 1 on success and -1 on error
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
*_printf - prints output according to given format
*@format: pointer to a character string
*@...: the given format
*
*Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int no_of_characters = 0;
	va_list aps;

	va_start(aps, format);
	while (*format != '\0')
	{
		if (*format != '%' && (*format - 1) != '%')
		{
			_putchar(*format);
			no_of_characters++;

		}

		if (*format == '%')
		{
			if (*(format + 1) == 'c')
			{
				char c = va_arg(aps, int);

				_putchar(c);
				no_of_characters++;
				format++;
			}
			if (*(format + 1) == '%')
			{
				_putchar('%');
				no_of_characters++;
				format++;
			}
			if (*(format + 1) == 's')
			{
				char *s = va_arg(aps, char *);

				while (*s)
				{
					_putchar(*s);
					no_of_characters++;
					s++;
				}
				format++;
			}

			if (*(format + 1) == 'd' || *(format + 1) == 'i')
			{
				int k = va_arg(aps, int);
				char buff[12];
				int number_length = change_to_string(k, buff);
				int j = 0;

				for (j = 0; j < number_length; j++)
				{
					_putchar(buff[j]);
					no_of_characters++;
				}
				format++;
			}
			if (*(format + 1) == 'b')
			{
				unsigned int no = va_arg(aps, unsigned int);
				char *binary = change_unsigned_int_to_binary(no);
				int i = 0;

				for (i = 0; binary[i] != '\0'; i++)
				{
					if (binary[i] == ' ')
					{
						continue;
					}
					else
					{
						_putchar(binary[i]);
					}
				}
				free(binary);
				format++;
			}
		}
		format++;
	}
	va_end(aps);
	return (no_of_characters);
}
