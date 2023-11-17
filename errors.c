#include "shell.h"

/**
 *_eputs - a function prints an input string
 * @str: function parameter
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - a function that writes the character c to stderr
 * @c : function parameter
 * Return: 1, -1 and errno
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - a function that writes the character c to given fd
 * @c: parameter 1
 * @fd: parameter 2
 * Return: 1, -1 and errno
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 *_putsfd - a function that prints an input string
 * @str: parameter 1
 * @fd: parameter 2
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}

