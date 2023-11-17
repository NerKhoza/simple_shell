#include "shell.h"

/**
 * _strcpy - a function that copies a string
 * @dest: parameter 1
 * @src: parameter 2
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - a function that duplicates a string
 * @str: function parameter
 * Return: pointer
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
		return (NULL);
	for (length++; length--;)
		rt[length] = *--str;
	return (rt);
}

/**
 *_puts - a function prints an input string
 *@str: function parameter
 * Return: Nothing
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - a function writes the character c to stdout
 * @c: parameter 1
 * Return: 1
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

