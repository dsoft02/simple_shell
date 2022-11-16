#include "shell.h"
/**
 * lennum - length of number
 * @n: int
 * Return: length
 */
int lennum(int n)
{
	int len = 0;

	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * int_to_char - take an int and convert to string
 * @num: integer to be printed
 * Return: string
 */

char *int_to_char(int num)
{
	int digit = 0;
	int i = 0;
	char *str;
	int divisor = 1000000000;
	int len = lennum(num);

	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);

	if (num < 10)
	{
		str[i++] = num + '0';
		str[i] = '\0';
		return (str);
	}

	while (divisor)
	{
		digit = (num / divisor) % 10;
		if (digit != 0 || (len >= 0 && str[i - 1] >= '0'))
		{
			str[i] = digit + '0';
			i++;
			len--;
		}
		divisor /= 10;
	}
	str[i] = '\0';
	return (str);
}

/**
 * _strcpy - unction that copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}

/**
 * _compare - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: Nohing
*/
int _compare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * _strstr - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: pointer to the first occurence
*/
char *_strstr(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && _compare(x, y))
			return (x);
		x++;
	}

	return (NULL);
}

