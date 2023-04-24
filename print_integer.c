#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_integer- prints integer
 * @ap:list of argumen
 *
 * Return: always 0
 */
int print_integer(int *num)
{
    int x = *num;
    int index = 0;

    if (x == 0)
    {
	    _putchar('-');
	    x = -x;
	    index++;
    }

    if (x / 10)
	    index = index + print_integer(&x);

    _putchar((x % 10) + '0');
    index++;

    return (index);
}
