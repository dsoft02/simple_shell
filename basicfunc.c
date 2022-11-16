#include "shell.h"

/**
*_putchar - prints each character
*@c : character
*Return: return the write value
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
*_puts - prints a string
*@str: string
*/

void _puts(char *str)
{
	int i;

	for (i = 0; strc[i] != '\0'; i++)
		_putchar(strc[i]);
	_putchar('\n');
}
